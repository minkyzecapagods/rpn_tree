#ifndef TREESERVICE_HPP
#define TREESERVICE_HPP

#include "node.hpp"
#include <string>



/**
 * @file treeService.hpp
 * @brief Functions for constructing, evaluating, and printing expression trees from RPN.
 */

/**
 * @brief Converts a Reverse Polish Notation (RPN) expression string into a binary expression tree.
 *
 * Each operator consumes the top two nodes from a stack to create a new operator node.
 * Numeric tokens create leaf nodes. Throws an exception if the RPN expression is invalid.
 *
 * @param rpn The input RPN expression string.
 * @return NodePtr Root of the constructed expression tree.
 * @throws std::runtime_error if the expression is invalid (e.g., not enough operands, invalid characters).
 */
NodePtr rpnToTree(const string& rpn);

/**
 * @brief Converts a binary expression tree into a standard infix notation string.
 *
 * Adds parentheses around operator nodes to preserve evaluation order.
 *
 * @param n Root node of the expression tree.
 * @return std::string The expression in standard infix notation.
 */
string treeToExp(NodePtr n);

/**
 * @brief Evaluates the value of a binary expression tree.
 *
 * Recursively computes the value of the tree. Throws if division by zero occurs.
 *
 * @param n Root node of the expression tree.
 * @return int Result of evaluating the expression.
 * @throws std::runtime_error if a division by zero is attempted.
 */
int evalTree(NodePtr n);

/**
 * @brief Returns a string representing the expression tree in a visual pre-order format.
 *
 * Example output:
 * @code
 * *
 * ├──4
 * └──+
 *     ├──3
 *     └──2
 * @endcode
 *
 * @param root Root node of the expression tree.
 * @return std::string Formatted string visualizing the tree structure.
 */
string traversePreOrder(NodePtr root);

#endif