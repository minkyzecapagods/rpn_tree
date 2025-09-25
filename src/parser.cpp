#include "../include/parser.hpp"
#include <charconv>

using namespace std;

/**
 * @brief Checks whether a string represents a valid integer number.
 *
 * This function uses std::from_chars to verify if the entire string
 * can be interpreted as an integer, optionally with a leading '-'.
 *
 * @param s The input string to check.
 * @return true If the string represents a valid integer.
 * @return false Otherwise (contains non-numeric characters, empty string, only a sign or invalid format).
 */
bool isNumber(const string& s) {	
    int value;
    auto [ptr, ec] = from_chars(s.data(), s.data() + s.size(), value);
    return ec == errc() && ptr == s.data() + s.size();
}

/**
 * @brief Checks whether a string represents a valid arithmetic operator.
 *
 * Valid operators are: '+', '-', '*', '/'.
 *
 * @param s The input string to check.
 * @return true If the string is a single character operator.
 * @return false Otherwise.
 */
bool isOp(const string& s) {
	string ops = "+-*/";
	if  (s.length() == 1 &&
		ops.find(s) != string::npos) return true;
	return false;
}