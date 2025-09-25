#ifndef IO_HPP
#define IO_HPP

#include "node.hpp"
#include <unordered_map>
#include <functional>


/**
 * @file io.hpp
 * @brief Handles command-line flags, global options, and help output for rpn_tree.
 */

/**
 * @brief Whether to print the expression tree.
 */
extern bool printTree;

/**
 * @brief Whether to print the expression in standard (infix) notation.
 */
extern bool printExp;

/**
 * @brief Flag to indicate program termination (e.g., after displaying help).
 */
extern bool quit;

/**
 * @brief Map of command-line flags and their associated actions.
 *
 * Keys are flag strings (e.g., "-h", "--help") and values are functions
 * executed when the flag is present.
 */
extern unordered_map<string, function<void()>> flags;

/**
 * @brief Prints the program manual/help page to stdout.
 *
 * Displays usage, options, return codes, and author information.
 */
void printMan();

#endif