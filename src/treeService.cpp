#include "../include/node.hpp"
#include "../include/parser.hpp"
#include <stack>
#include <sstream>

using namespace std;

/**
 * @brief Converts a RPN expression string into a binary expression tree.
 *
 * @param rpn The RPN expression as a string (e.g., "3 4 + 2 *").
 * @return NodePtr The root of the generated expression tree.
 * @throws runtime_error If the expression is invalid (not enough operands, unknown tokens, too many operands).
 */
NodePtr rpnToTree(const string& rpn) {

  	istringstream exp(rpn);
	string token;
	stack<NodePtr> stack;

	while (exp >> token) {
		if (isNumber(token)) {
			int num = stoi(token);
			NodePtr n = make_shared<Node>(num);
			stack.push(n);
			continue;
		} else if (isOp(token)) {
			if (stack.size() < 2) {
    			throw runtime_error("Error: Invalid RPN expression.\nNot enough operands for operator.\n");
			}
			NodePtr right = stack.top();
			stack.pop();
			NodePtr left = stack.top();
			stack.pop();
			NodePtr n = make_shared<Node>(token[0], left, right);
			stack.push(n);
			continue;
		}
		throw runtime_error("Error: Invalid sequence of characters '" + token + "' in expression.\n");
	}

	if (stack.size() > 1)
    	throw runtime_error("Error: Invalid RPN expression.\nToo many operands.\n");

    return stack.top();
}

/**
 * @brief Converts a binary expression tree into a string in infix notation.
 *
 * Parentheses are added to preserve correct order of operations.
 *
 * @param n The root of the expression tree.
 * @return string The expression as a string in infix form.
 */
string treeToExp(NodePtr n) {
    if (n -> isOp) {
        string left = treeToExp(n -> left);
        string right = treeToExp(n -> right);
        if (n -> left -> isOp)
            left = "(" + left + ")";
        if (n -> right -> isOp)
            right = "(" + right + ")";
        return left + n -> op + right;
    }
    return to_string(n -> num);
}

/**
 * @brief Evaluates the expression represented by the binary tree.
 *
 * @param n The root of the expression tree.
 * @return int The evaluated integer result.
 * @throws runtime_error If a division by zero occurs.
 */
int evalTree(NodePtr n) {
	if (n -> isOp) {
		switch (n -> op) {
			case '+': 
				return evalTree(n -> left) + evalTree(n -> right);
			case '-': 
				return evalTree(n -> left) - evalTree(n -> right);
			case '*': 
				return evalTree(n -> left) * evalTree(n -> right);
			case '/': {
                int right = evalTree(n -> right);
                int left = evalTree(n -> left);
                if (right == 0)
                    throw runtime_error("Error: Invalid RPN expression.\nDivision by zero.\n");
				return left / right;
            }
		}
	}
	return n -> num;
}

/**
 * @brief Helper function to recursively traverse and build an ASCII tree string.
 *
 * @param padding The current padding string for tree levels.
 * @param pointer The pointer characters (├──, └──) for the current node.
 * @param node The current node to print.
 * @param hasRightSibling Whether the current node has a right sibling.
 * @return string ASCII representation of the subtree rooted at node.
 */
string traverseNodes(string padding, string pointer, NodePtr node, bool hasRightSibiling) {
    string tree = "";
    
    if (node != nullptr) {

        string value = "";
        if (node -> isOp) value += node -> op;
        else value += to_string(node -> num);
        tree = "\n" + padding + pointer + value;

        if (hasRightSibiling) padding += "│  ";
        else padding += "   ";

        string pointerRight = "└──";
        string pointerLeft = "";
        if (node -> right != nullptr) pointerLeft += "├──";
        else pointerLeft += "└──";

        tree += traverseNodes(padding, pointerLeft, node -> left, node -> right != nullptr);
        tree += traverseNodes(padding, pointerRight, node -> right, false);
    }

    return tree;
}


/**
 * @brief Returns an ASCII representation of the entire expression tree.
 *
 * @param root The root of the expression tree.
 * @return string The ASCII-art string of the tree.
 */
string traversePreOrder(NodePtr root) {
    
    string tree = "";
    if (root -> isOp) tree += root -> op;
    else tree += to_string(root -> num);

    string pointerRight = "└──";
    string pointerLeft = "";
    if (root -> right != nullptr) pointerLeft += "├──";
    else pointerLeft += "└──";

    tree += traverseNodes("", pointerLeft, root -> left, root -> right != nullptr);
    tree += traverseNodes("", pointerRight, root -> right, false);
    return tree;
}