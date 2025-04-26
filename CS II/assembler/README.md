# CS23001 Project 3

---

\*\*CS 23001 Computer Science II: Data Structures & Abstraction  
Project #3

Spring 2025  
\*\*

---

**Objectives:**

- Develop and use the stack ADT.
- Use String ADT from program 2.
- Use linked lists.
- Use stack algorithms and postfix, infix, prefix notations.

**Problem:**  
Convert an infix expression into assembler.

Assembler languages are the simplest of programming languages. It is very close to what the CPU reads to execute programs. Assembly can be directly converted into machine instructions in hexadecimal and executed by the CPU. All high level programming languages (e.g., C++, Pascal) are converted into assembly through the compiling process. The final phase of the compiler is code generation. This programming project will give you a feel for the solution to (a small part of) the code generation process.

Here you are given a simple CPU with only one register and six instructions (akin to RISC architectures). The instructions (or commands) can only work with the register and one operand (parameter). The table below describes the instruction set. The instructions act on the single register. The register is the only place where operations can be executed. That is, it is the only "variable" to which you can add, subtract, multiply, or divide. You cannot add two memory locations together; the contents of a location must be loaded into the register and the contents of a location is then added to the register. The results of this computation can then be stored to some memory location.

**Instruction set:**

<table border="0" cellpadding="7" cellspacing="0" width="421"><tbody><tr><td valign="top" width="20%"><code>LD opn </code></td><td valign="top" width="80%">Loads operand into the register.</td></tr><tr><td valign="top" width="20%"><code>ST opn</code></td><td valign="top" width="80%">Stores the contents of register to operand.</td></tr><tr><td valign="top" width="20%"><code>AD opn</code></td><td valign="top" width="80%">Adds contents of operand to register.</td></tr><tr><td valign="top" width="20%"><code>SB opn</code></td><td valign="top" width="80%">Subtracts.</td></tr><tr><td valign="top" width="20%"><code>MU opn</code></td><td valign="top" width="80%">Multiplies.</td></tr><tr><td valign="top" width="20%"><code>DV opn</code></td><td valign="top" width="80%">Divides.</td></tr></tbody></table>

Your problem is to convert a given infix expression into a sequence of assembly instructions that evaluates the expression and leaves the result in the register. You will do this by using postfix expressions. First, you will convert a given infix expression into the corresponding postfix expression. In the second step, you will convert postfix to the required sequence of assembly instructions. You will read the infix expression from a file, and write the result to another file.

**For example,**  
given the following infix expression:  
( ( A + ( B \* C ) ) / ( D - E ) )

we get the postfix expression:  
A B C \* + D E - /

This results in an assembly program that looks like:

<table border="0" cellpadding="7" cellspacing="0" width="629"><tbody><tr><td valign="top" width="15%"><b>Opcode</b></td><td valign="top" width="15%"><b>Operand</b></td><td valign="top" width="70%"><b>Comment</b></td></tr><tr><td valign="top" width="15%">LD</td><td valign="top" width="15%">B</td><td valign="top" width="70%">Load in B.</td></tr><tr><td valign="top" width="15%">MU</td><td valign="top" width="15%">C</td><td valign="top" width="70%">B * C.</td></tr><tr><td valign="top" width="15%">ST</td><td valign="top" width="15%">TMP1</td><td valign="top" width="70%">Save results of B * C.</td></tr><tr><td valign="top" width="15%">LD</td><td valign="top" width="15%">A</td><td valign="top" width="70%">Load A.</td></tr><tr><td valign="top" width="15%">AD</td><td valign="top" width="15%">TMP1</td><td valign="top" width="70%">Add A to B * C.</td></tr><tr><td valign="top" width="15%">ST</td><td valign="top" width="15%">TMP2</td><td valign="top" width="70%">Save result.</td></tr><tr><td valign="top" width="15%">LD</td><td valign="top" width="15%">D</td><td valign="top" width="70%">Load D.</td></tr><tr><td valign="top" width="15%">SB</td><td valign="top" width="15%">E</td><td valign="top" width="70%">D - E.</td></tr><tr><td valign="top" width="15%">ST</td><td valign="top" width="15%">TMP3</td><td valign="top" width="70%">Save result.</td></tr><tr><td valign="top" width="15%">LD</td><td valign="top" width="15%">TMP2</td><td valign="top" width="70%">Get A + B * C.</td></tr><tr><td valign="top" width="15%">DV</td><td valign="top" width="15%">TMP3</td><td valign="top" width="70%">Divide it by D - E.</td></tr><tr><td valign="top" width="15%">ST</td><td valign="top" width="15%">TMP4</td><td valign="top" width="70%">Save result, also still in register.</td></tr></tbody></table>

**Your program output should be:**

```

Infix Expression: ( ( AX + ( BY * C ) ) / ( D4 - E ) )
Postfix Expression: AX BY C * + D4 E - /

  LD     BY
  MU     C
  ST     TMP1
  LD     AX
  AD     TMP1
  ST     TMP2
  LD     D4
  SB     E
  ST     TMP3
  LD     TMP2
  DV     TMP3
  ST     TMP4
```

**Requirements:**

- You CANNOT use std::string and must construct your stack using a linked list you build. You MUST use your String class from assignment 2.
- Name the folder for this project: `assembler`.
- **Milestone 1** - 30 pts

- Implementation:

- There is a Makefile, stack interface, and data files in `shared`.
- Create a generic (template) ADT stack class (using interface given).
- Implement using a linked list.
- You must implement a destructor, copy constructor, constant time swap, and assignment.
- You will need to have a stack of strings for other parts of this project.
- The makefile is currently set up to look for your string code in `../string/`. Note that you should do a make clean in your /string folder to make sure string.o is not still there. It will also look for string.\* in the current folder (assembler/) if you make a copy and put it there.
- Use `#include "../string/string.hpp"` to include your string from project 2 in your project 3 files.

- Testing:

- Create unit tests that throughly tests your stack class. This will be the main component of your grade. Make sure to test with your string class and other built in types (e.g., integer). You do NOT need a test for full.
- Write test cases first. Testing must be thorough. You will be relying on the string to be correct.
- `make test` - should build and run your tests.
- After each function passes a test, commit your work to svn with a message like "Constructor tests passed".

- **Milestone 2** - 30 pts

- Implementation:

- Construct a _free_ function that converts infix to postfix. Put this function in `utilities.cpp/hpp`.
- Read in a fully parenthesized infix expression and covert it to postfix.
- Input file format: A fully parenthesized valid infix expression. There will be blanks between each token. Operands are 1 to 6 charaters in length and the operators: +, -, \*, /. One expression per line, read until end of file is reached. Each expression will end in a semi-colon (;). You may assume that all input is **valid**.
- Since each token of the input is separated by spaces you can easily read in one token at a time. There are numerous ways you can read the expression in. If you check for end of line, be aware that there are multiple EOLN characters (e.g., '\\n', '\\r'). You can read more [here](https://en.wikipedia.org/wiki/Newline).
- Use your stack class from milestone 1 (linked list version) and string class from project 2. You string should be correct and well tested.
- Algorithm: Infix-to-Postfix. Stack is empty, expr is fully parenthesized valid infix expression

- read token
- While (token != ";") do

- if token is a ")" then

- right = pop stack
- oper = pop stack
- left = pop stack
- push(left + right + oper)

- else

- if token is not a "(" push(token)

- read token

- end while
- Top of stack is a postfix expression

- Create a main file named `postfix.cpp` that reads a set of infix expressions from a file and writes the infix and postfix expressions to another file. It will include `utilities.hpp`
- Build the following command line interface:

- `postfix input [output]` where the input file name is required and an optional output file name. If no output file is specified it will default to the screen.

- `make postfix` should build the application.

- Testing:

- Create a data set that properly tests the conversion algorithm.
- Your program should work for the data3-1.txt data file in the shared directory.
- Commit all your work and files to svn - as you go.

- **Milestone 3** - 40 pts

- Implementation:

- Write a free function to convert the postfix expression into assembly. Put this in `utilities.cpp/hpp`.
- You may use your split function from project2 to get each token from the postfix expression.
- Algorithm: Evaluated Postfix. Stack is empty, expr is a valid postfix expression. This algorithm needs to be augmented to solve the postfix to assembly problem.

- While (not done with expr) do

- t = next token in expr // You can use find next blank and substr.
- if t is NOT an operator then

- push(t)

- else

- right = pop stack
- left = pop stack
- push evaluate(left, t, right)

- endif

- end while
- Top of stack has value

- You will need to write a special evaluate function to produce the assembly and temporary memory locations. This function will need to output the assembly to an ofstream.
- For temporary variables use the form TMPn to save intermediate results. n is in the range of 1 to maxint.
- Create a main file (modify your main from milestone 2) named **assembler.cpp** that reads in all the infix expressions in a file given on the command line and writes the expression, the postfix, and the assembly code to a file (optional name on command line otherwise to standard output).
- Output format: Sequence of assembly instructions that evaluate the expression. The instruction must start in column 4 and the operand starts in column 10. See the program output example above.
- `make assembler` should build the application.
- You must use your ADT Stack and String.

- Testing:

- Test your program with the provided data files. See the data files in the shared directory.

- **Challenge (Required for Honors Students):** - 10 pts extra credit on this project

- Develop an algoithm to evaluate prefix expressions.
- Is it more complex than evaluating postfix? Why?
- Write the code to convert the expressions to prefix and generate assembler from the prefix expressions.
- Is the resulting assembler more complex?

- **Other Requirements:**

- You must have a separate specification file (.hpp), implementation file (.cpp), and main file.
- Your program will be graded on programming and commenting style as well as the implementation of your ADT.
- Include all source code files in svn.
- You can NOT use STL (other than for the split function), any other library, or built in methods to solve this problem.
- See the grading policy for other requirements.

---

URL: https://data-structures.cs.kent.edu/projects/proj3.html  
Last update: 03/17/2025 17:31:47 EST

---
