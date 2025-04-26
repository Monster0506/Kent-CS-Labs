//
// File: utilities.cpp
//
// Description: Implementation of utility functions for assembler
//

#include "utilities.hpp"
#include "../string/string.hpp"
#include "stack.hpp"
void writeAssembly(std::ostream &out, const char *op, const String &operand)
{
  out << "   " << op;

  int opLen = 3;
  int padding = 10 - (opLen + 3);
  for (int i = 0; i < padding; ++i)
  {
    out << ' ';
  }

  out << operand << "\n";
}

String intToString(int num)
{
  char buffer[16];
  int i = 0;

  if (num == 0)
  {
    buffer[i++] = '0';
  }
  else
  {
    while (num > 0 && i < 15)
    {
      buffer[i++] = '0' + (num % 10);
      num /= 10;
    }
  }

  buffer[i] = '\0';

  for (int j = 0; j < i / 2; ++j)
  {
    char temp = buffer[j];
    buffer[j] = buffer[i - j - 1];
    buffer[i - j - 1] = temp;
  }

  return String(buffer);
}

void postfixToAssembly(const String &postfix, std::ostream &out)
{
  stack<String> evalStack;
  String tokens[100];
  int tokenCount = 0;

  String temp = "";
  for (int i = 0; i < postfix.length(); ++i)
  {
    char c = postfix[i];
    if (c != ' ')
    {
      temp += c;
    }
    else if (temp != "")
    {
      tokens[tokenCount++] = temp;
      temp = "";
    }
  }
  if (temp != "")
    tokens[tokenCount++] = temp;

  int tmpCounter = 1;

  for (int i = 0; i < tokenCount; ++i)
  {
    String token = tokens[i];

    if (token == "+" || token == "-" || token == "*" || token == "/")
    {
      String right = evalStack.pop();
      String left = evalStack.pop();
      String tmpName = String("TMP") + intToString(tmpCounter++);
      const char *opCode = "";

      if (token == "+")
        opCode = "AD";
      else if (token == "-")
        opCode = "SB";
      else if (token == "*")
        opCode = "MU";
      else if (token == "/")
        opCode = "DV";

      writeAssembly(out, "LD", left);
      writeAssembly(out, opCode, right);
      writeAssembly(out, "ST", tmpName);

      evalStack.push(tmpName);
    }
    else
    {
      evalStack.push(token);
    }
  }

  String finalResult = evalStack.pop();
  String finalTmp = String("TMP") + intToString(tmpCounter++);
  writeAssembly(out, "LD", finalResult);
  writeAssembly(out, "ST", finalTmp);
}

String infixToPostfix(const String &expr)
{
  if (expr.length() == 0 || (expr[expr.length() - 1] != ';' && expr[expr.length() - 2] != ';'))
  {
    return String("Error: Expression must end with semicolon");
  }

  stack<String> S;
  std::vector<String> tokens = expr.split(' ');
  for (int i = tokens.size() - 1; i >= 0; --i)
  {
    String t = tokens[i];

    if (t == ")")
    {
      S.push(t);
    }
    else if (t == "(")
    {
      String lhs = S.pop();

      String op = S.pop();
      String rhs = S.pop();

      S.pop();

      String result = lhs + " " + rhs + " " + op;
      S.push(result);
    }
    else if (t != ";")
    {
      S.push(t);
    }
  }

  return S.pop();
}


// Slightly more complicated, as you have to iterate backwards through the expression, but not much more difficult.
String infixToPrefix(const String &expr)
{
  if (expr.length() == 0 || (expr[expr.length() - 1] != ';' && expr[expr.length() - 2] != ';'))
  {
    return String("Error: Expression must end with semicolon");
  }

  stack<String> S;
  std::vector<String> tokens = expr.split(' ');
  for (int i = tokens.size() - 1; i >= 0; --i)
  {
    String t = tokens[i];

    if (t == ")")
    {
      S.push(t);
    }
    else if (t == "(")
    {
      String lhs = S.pop();

      String op = S.pop();
      String rhs = S.pop();

      S.pop();

      String result = op + " " + lhs + " " + rhs;
      S.push(result);
    }
    else if (t != ";")
    {
      S.push(t);
    }
  }

  return S.pop();
}

// Resulting ASM is exactly the same
void prefixToAssembly(const String& prefix, std::ostream& out) {
  stack<String> evalStack;
  String tokens[100];
  int tokenCount = 0;

  String temp = "";
  for (int i = 0; i < prefix.length(); ++i) {
    char c = prefix[i];
    if (c != ' ') temp += c;
    else if (temp != "") {
      tokens[tokenCount++] = temp;
      temp = "";
    }
  }
  if (temp != "") tokens[tokenCount++] = temp;

  int tmpCounter = 1;

  for (int i = tokenCount - 1; i >= 0; --i) {
    String token = tokens[i];

    if (token == "+" || token == "-" || token == "*" || token == "/") {
      String left = evalStack.pop();
      String right = evalStack.pop();

      String tmp = String("TMP") + intToString(tmpCounter++);
      const char* op = (token == "+") ? "AD" :
        (token == "-") ? "SB" :
        (token == "*") ? "MU" :
        (token == "/") ? "DV" : "";

      writeAssembly(out, "LD", left);
      writeAssembly(out, op, right);
      writeAssembly(out, "ST", tmp);

      evalStack.push(tmp);
    } else {
      evalStack.push(token);
    }
  }

  String result = evalStack.pop();
  String finalTmp = String("TMP") + intToString(tmpCounter++);
  writeAssembly(out, "LD", result);
  writeAssembly(out, "ST", finalTmp);
}
