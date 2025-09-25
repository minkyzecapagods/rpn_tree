#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

/**
 * @file parser.hpp
 * @brief Functions for parsing and validating RPN expressions.
 */

/**
 * @brief Checks whether a string represents a valid integer number.
 * 
 * This function accepts optional leading '-' signs.
 *
 * @param s The input string to check.
 * @return true If the string represents a valid integer.
 * @return false Otherwise (contains non-numeric characters, empty string, only a sign or invalid formate).
 */
bool isNumber(const std::string& s);

/**
 * @brief Checks whether a string represents a valid arithmetic operator.
 *
 * Valid operators are '+', '-', '*', '/'.
 * 
 * @param s The input string to check.
 * @return true If the string is a single character operator.
 * @return false Otherwise.
 */
bool isOp(const std::string& s);

#endif