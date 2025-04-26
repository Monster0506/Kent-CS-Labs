# CS2 Lab - Infix Expression

# Lab - Infix Expression

---

## Objectives

- Understand Infix to Prefix conversion
- Write out code to do Infix to Prefix conversion
- Talk about evaluating these expressions

---

## Discussion

- Prefix, Infix, and Postfix are useful for several purposes. Primarily:

- Ease of parsing and converting prefix and postfix
- Ease of reading infix expressions and evaluating them

- Evaluating the expression is a matter of knowing which token you're dealing with.
- Refresher from lecture - Infix to Prefix/Postfix pseudocode:

```
expr = /*Some Infix Expression*/;
Stack S;
while (not done with expr) { // For each token in the infix expression
    t = nextToken(expr);
    if (t == ')') { // If a right parenthesis, then combine into subexpression
        rhs = S.pop();
        op  = S.pop();
        lhs = S.pop();
        s.push( lhs + rhs + op ); // Convert to Postfix form - do op + lhs + rhs for Prefix
    } else if (t != '(') { // Push everything except left parenthesis
        S.push(t)
    }
}
return S.pop();
```

- A visual example of this algorithm can be read [here](https://data-structures.cs.kent.edu/labs/Info/infix_to_prefix_example.pdf).

---

## Setup

We need to:

1.  Create a directory called _infix2prefix_ in your _cs23001_ folder
2.  Create a file named `infix2prefix.cpp` in the _infix2prefix_ directory
3.  Copy the `data3-1.txt` file from the shared folder to your _infix2prefix_ directory

---

## Naming Quiz

As a part of your lab assignment, you must complete a quiz in Canvas. This quiz will cover naming conventions.

You have the entire lab to complete the quiz. You may not complete this quiz outside of your lab.

---

## Assignment

Create a function that converts an infix expression to prefix expression.

Your function should operate properly on any valid, fully parenthesized infix expression ended by a '`;`'. Each token of the expression will be separated by a space (''). Example: ` ( ( A + B ) * C ) ;`

Your code must make use of your Stack class from Project 3 Milestone 1 and your String class from Project 2 Milestone 4. You will also need to include `vector`.

---

## Requirements

The following should be true when you are done, **NAMES MUST MATCH EXACTLY**:

- In your _cs23001_ directory you have created a directory named _infix2prefix_.
- In the directory _infix2prefix_ you have the following files:

- `infix2prefix.cpp`
- `data3-1.txt`

- There are **NO** executables in the repository.
- Your program compiles, runs, and performs as specified.
- Your program follows the [General Program Requirements](https://data-structures.cs.kent.edu/labs/Info/general_prog_req.html).

---

URL: https://data-structures.cs.kent.edu/labs/Lab11  
Last update: 03/31/2025 17:40:32 EST

---
