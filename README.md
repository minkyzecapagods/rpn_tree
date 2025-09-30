# rpn_tree

rpn_tree is a C++ program that builds and evaluates a binary expression tree from a Reverse Polish Notation (RPN) expression. 
The program supports integer values and basic arithmetic operators (+, -, *, /). 
It processes the expression from left to right using a stack-based algorithm and constructs a binary tree where internal nodes represent operators and leaf nodes represent numeric values. 
The resulting tree can be evaluated to compute the expression's value, printed in infix notation, or visualized as a structured tree.

This project was developed as part of the course requirements for **Object-Oriented Programming (EDB2)**.

## Project Specifications

- Implement a binary tree to represent arithmetic expressions from Reverse Polish Notation.
- Nodes must store either integer values or arithmetic operators (*, /, +, -).
- Process elements left-to-right using a stack.
- Create leaf nodes for numeric values and push them onto the stack.
- When an operator is encountered, pop the top two nodes from the stack, create a new operator node with these as children, and push it back.
- After processing the expression, the top of the stack will contain the complete expression tree.


## About Reverse Polish Notation (RPN)  
Reverse Polish Notation (RPN), also known as *postfix notation*, is a mathematical notation in which every operator follows all of its operands.  
Unlike the common infix notation (e.g., `(1 + 2) * 3`), RPN does not require parentheses to define the order of operations. The expression is evaluated strictly from left to right using a stack.

### How to write an RPN expression:
&ensp; 1. Write the operands (numbers) first.

&ensp; 2. Write the operator right after its operands.

&ensp; 3. Repeat this process for the whole expression.

For example:
- Infix: `(1 + 2) * 3`  
- RPN: `1 2 + 3 *`

Another example:
- Infix: `((1 + 2) - 293) / -2`  
- RPN: `1 2 + 293 - -2 /`

### Benefits of RPN:
- No need for parentheses, even in complex expressions.
- Simple to evaluate using a stack-based algorithm.
- Widely used in calculators and compilers.
## Features

- Converts RPN expressions to a binary tree;
- Evaluates the expression;
- Prints the tree structure in a visually appealing format;
- Prints the expression in standard infix notation;
- Command-line flags for help, tree view, and expression output;
- Error handling for invalid expressions and division by zero.
## Requirements
- CMake >= 3.16  
- C++20 compatible compiler (e.g., `g++`, `clang++`)  
## Build Instructions
```bash
# Clone repository
git clone https://github.com/minkyzecapagods/rpn_tree.git
cd rpn_tree

# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Compile
cmake --build 
```
The compiled executable will be placed in `build/bin/rpn_tree`.

### Clear
```bash
cmake --build . --target clear
```
## Installation

To install the program system-wide:
```bash
sudo cmake --install build
```
By default, the executable is copied to `/usr/local/bin/rpn_tree`.
Now, you can run the application from anywhere in your device with `rpn_tree`.

### Uninstall
To uninstall the application from your system, simply run:
```bash
sudo rm /usr/local/bin/rpn_tree
```
## Usage/Examples

#### If installed system-wide
```bash
rpn_tree
```
#### If not installed (run from build directory)
```bash
./bin/rpn_tree
```
#### Optional flags
- -h | --help : Show usage instructions;
- -t | --tree : Enable display of the expression in binary tree format;
- -i | --infix : Enable display of the expression in infix notation.

#### Expression
An expression in Reverse Polish Notation (RPN) must be provided as the last argument to the program.
It should be passed as a single string enclosed in quotation marks, so that the shell does not split the tokens.

### Example
##### Input:
```bash
# When installed system wide
rpn_tree -t -i "1 2 + 293 - -2 /"

# When run from build directory
./bin/rpn_tree -t -i "1 2 + 293 - -2 /"
```
##### Output:
```bash
The expression's value is 145.

Expression as a binary tree:
/
├──-
│  ├──+
│  │  ├──1
│  │  └──2
│  └──293
└──-2

Expression in infix notation: ((1 + 2) - 293) / -2
```
## Documentation

The project uses Doxygen for automatic code documentation.

To generate:
```bash
doxygen Doxyfile
```

#### How to open the documentation in your browser:
```bash
# In Linux:
xdg-open docs/html/index.html

# In MacOS:
open docs/html/index.html

# In Windows:
open docs/html/index.html
```

## License
This project was made for educational purposes and is licensed under the MIT License.  
See the [LICENSE](https://choosealicense.com/licenses/mit/) file for details.

