#include "../include/io.hpp"
#include "../include/parser.hpp"
#include "../include/node.hpp"
#include "../include/treeService.hpp"
#include <cstring>
#include <iostream>

using namespace std;

/**
 * @file main.cpp
 * @brief Main entry point for the rpn_tree program.
 *
 * This program reads a Reverse Polish Notation (RPN) expression from the
 * command line, builds a binary expression tree, evaluates it, and optionally
 * prints the tree or the expression in infix notation.
 *
 * Usage example:
 * @code
 * ./rpn_tree -t -e "3 4 + 2 *"
 * @endcode
 *
 * Command-line flags:
 * - -h, --help : display help and exit
 * - -t, --tree : display the expression tree
 * - -i, --infix : display the expression in infix notation
 */
int main(int argc, char* argv[]) {

	// Check if at least one argument was provided
	if (argc < 2) {
		cerr << 
			"Error: Invalid number of arguments.\n"
			"View manual with ./rpn_tree [-h | --help].\n";
		return 1;
	}

	// Process command-line flags
	for (int i = 1; i < argc; i++) {
		if (flags.count(argv[i]))
			flags.at(argv[i])(); // call the function for the flag
		else if (i != argc - 1) {
			cerr << 
				"Error: Invalid flag '" << argv[i] << "'.\n"
				"View manual with ./rpn_tree [-h | --help].\n";
			return 1;
		}
		if (quit) return 0; // quit if help was requested
	}

	// Validate and parse the last argument (RPN expression)
	if (strlen(argv[argc - 1]) == 0) return 0;

	NodePtr root;
	int res;

	try {
		root = rpnToTree(argv[argc - 1]);
		res = evalTree(root);
	} catch (const exception& e) {
		cerr << e.what();
		return 2;
	}

	cout << "The expression's value is " << res << ".\n";

	if (printTree)
		cout << "\nExpression as a binary tree:\n" << traversePreOrder(root) << "\n";
	
	if (printExp)
		cout << "\nExpression in infix notation: " << treeToExp(root) << "\n";

	return 0;
 }