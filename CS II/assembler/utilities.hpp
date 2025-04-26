//
// File: utilities.hpp
//
// Description: Utility functions for assembler, including infix to postfix
// conversion
//

#ifndef CS2_UTILITIES_HPP_
#define CS2_UTILITIES_HPP_

#include "../string/string.hpp"
#include "stack.hpp"

// Convert a fully parenthesized infix expression to postfix
// PRE:  Infix expression is fully parenthesized and valid
//       Tokens are separated by spaces
//       Operands are 1-6 characters
//       Operators are +, -, *, /
//       Expression ends with semicolon
// POST: Returns the postfix expression as a String
String infixToPostfix(const String &infix);
String infixToPrefix(const String &expr);
void writeAssembly(std::ostream &out, const char *op, const String &operand);
void postfixToAssembly(const String &postfix, std::ostream &out);
void prefixToAssembly(const String &postfix, std::ostream &out);

#endif