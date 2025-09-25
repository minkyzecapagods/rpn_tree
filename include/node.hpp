#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
using namespace std;

/**
 * @file node.hpp
 * @brief Defines the Node structure and NodePtr type for the RPN expression tree.
 */

/**
 * @struct Node
 * @brief Represents a node in a binary expression tree.
 *
 * A node can be either an operator node or a numeric value node.
 * Operator nodes have left and right children, while value nodes are leaves.
 */

struct Node {
    int num;                    /**< Numeric value if the node is a leaf */
    char op;                     /**< Operator character if the node is an operator node ('+', '-', '*', '/') */
    std::shared_ptr<Node> left;  /**< Pointer to the left child node */
    std::shared_ptr<Node> right; /**< Pointer to the right child node */
    bool isOp;                   /**< True if the node is an operator, false if it is a numeric leaf */

	/**
     * @brief Constructs a numeric leaf node.
     * @param num The integer value of the node.
     */
	Node(int num): 
		num(num), left(nullptr), right(nullptr), isOp(false) {}

	/**
     * @brief Constructs an operator node with two children.
     * @param op The operator character ('+', '-', '*', '/').
     * @param left Pointer to the left child node.
     * @param right Pointer to the right child node.
     */
	Node(char op, shared_ptr<Node> left, shared_ptr<Node> right): 
		op(op), left(left), right(right), isOp(true) {}
};

/**
 * @brief Shared pointer type for Node.
 */
using NodePtr = std::shared_ptr<Node>;

#endif