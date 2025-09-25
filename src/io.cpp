#include "../include/io.hpp"
#include <iostream>

using namespace std;

/**
 * @brief Flag to indicate if the expression tree should be printed.
 */
bool printTree = false;


/**
 * @brief Flag to indicate if the expression in regular notation should be printed.
 */
bool printExp = false;


/**
 * @brief Flag to indicate whether the program should quit immediately (e.g., after help).
 */
bool quit = false;

/**
 * @brief Map of valid command-line flags and their associated actions.
 *
 * The keys are flag strings (e.g., "-h", "--tree") and the values are
 * functions that execute the corresponding behavior.
 */
unordered_map<string, function<void()>> flags = {
    {"-h", [] { printMan(); quit = true; }},
    {"--help", [] { printMan(); quit = true;}},
    {"-t", [] { printTree = true; }},
    {"--tree", [] { printTree = true; }},
    {"-r", [] { printExp = true; }},
    {"--regular", [] { printExp = true; }},
};

/**
 * @brief Prints the manual/help page for the rpn_tree program.
 *
 * This function outputs information about the program, including its
 * name, synopsis, description, return codes, possible errors, and author.
 * It is typically called when the user provides the -h or --help flags.
 */
void printMan() {
  cout << "NAME\n"
        << "\rpn_tree - Builds and evaluates an expression tree from Reverse Polish Notation.\n"
        << "\n"
        << "SYNOPSIS\n"
        << ".\rpn_tree [OPTIONS] \"[RPN_EXPRESSION]\"\n"
        << "\n"
        << "DESCRIPTION\n"
        << "\tThe rpn_tree program reads an arithmetic expression in Reverse Polish Notation\n"
        << "\tand constructs a binary tree to represent it. The expression must be provided\n"
        << "\tas a single string enclosed in quotes. The tree nodes can be either arithmetic\n"
        << "\toperators (+, -, *, /) or integer values.\n"
        << "\n"
        << "\t-h, --help\n"
        << "\t\tDisplay this help page and exit.\n"
        << "\t-t, --tree"
        << "\t\tDisplay the corresponding tree for the RPN expression.\n"
        << "\t-r, --regular"
        << "\t\tDisplay RPN expression in regular notation.\n"
        << "\n"
        << "RETURN CODES\n"
        << "\t0 - Success\n"
        << "\t1 - Argument error\n"
        << "\t2 - Invalid expression\n"
        << "\n"
        << "ERRORS\n"
        << "\t- Missing argument\n"
        << "\t- Invalid expression\n"
        << "\t- Non-numeric characters\n"
        << "\t- Division by zero\n"
        << "AUTHOR\n"
        << "\tminkyzecapagods\n"
        << "\n";
}