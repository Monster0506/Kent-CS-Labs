# CS23001 Project 4

---

\*\*CS 23001 Computer Science II: Data Structures & Abstraction  
Project #4

Spring 2025  
\*\*

---

**Objectives:**

- Develop and use a Tree ADT (n-ary)
- Apply and use tree traversal algorithms
- Manipulate trees by inserting and deleting nodes
- Apply and use the Standard Template Library (STL)

**Problem:**  
Build a program profiler. Construct a program to instrument C++ source code to support program profiling.

It is often important to determine how many times a function or statement is executed. This is useful not only for debugging but for determining what parts of a program may need to be optimized. This process is called profiling. That is, a execution profile presents how many times each part of a program is executed using a given set of input data (or for some run time scenario). To compute a profile, specialized statements need to be inserted in to the code that keep track of how many times a function or statement is executed. The process of inserting these statements is called instrumenting the code.

To implement a profiler one must first parse the source code and generate an Abstract Syntax Tree (AST) of the code. Each node of the AST describes the syntactic category of the code stored within it (function, statement, while-statement, etc.). So at the top level is a syntactic category corresponding to a program, class, or function (such as in the case of a main). Under that are sub-trees that further detail the syntactic categories of each part of the code. Such things as declarations, parameter lists, while-statement, and expression statements will describe the various parts of the program.

After the AST is generated it can then be traversed and the appropriate syntactic structures can be found that need to be instrumented. Once a construct is found, say a function, new code can be inserted that keeps track of how many times that function is executed.

The most difficult part of constructing a profiler is correctly parsing the source code. Unfortunately, C++ is notoriously difficult to parse. So here we will use a parsing tool called [srcML](http://www.srcml.org/). This tool reads in C++ code and marks up the code with XML tags (e.g., block, if, while, condition, name, etc). That is, the output is an AST in XML. The XML representation is called srcML (source code markup language).

Given the code example:

    ```

void foo(int x) {
++x;
}

```

The following is srcML 1.0 with tags. It is indented for readability and to see the tree structurue. The function has 4 children, the function type, the name of the function, the parameter\_list, and the block. Each <tag\> has an end-tag </tag\>, as in HTML.

```

<function>
    <type><name>void</name></type>
    <name>foo</name>
    <parameter_list>
        (
        <parameter><
            decl><type>
                <name>int</name>
                </type> <name>x</name>
            </decl>
        </parameter>
        )
    </parameter_list>
    <block>
        {<block_content>
        <expr_stmt>
            <expr>
                <operator>++</operator>
                <name>x</name>
            </expr>
            ;
        </expr_stmt>
        </block_content>}
    </block>
</function>
```

A number of srcML data files are provided for the project. However, you can use your own program as input. srcML is installed on wasp and hornet. To generate the srcML file for your own code use the following:  
`srcml main.cpp -o main.cpp.xml`

You can also generate srcML for small snippets of code:  
`srcml --text "if (a == 10) { i=i+1; }" --language C++`

Use the following for a list of all options:  
`srcml --help`

More information about srcML can be found at [www.srcML.org](http://www.srcml.org/) including a list of all the tag names (see Documentation). srcML can also be downloaded/installed locally on your machine.

The main srcML tag names needed for the project:

- <name\> - an identifier or function name
- <block\> - a block { stmts }
- <block_content\> - the stmts (contents) in a block { stmts }
- <function\> - a function or method
- <constructor\> - a constructor
- <destructor\> - a destructor
- <expr_stmt\> - an expression statement (e.g., a = 5 + x; cin \>\> x; ++i; foo(30);)
- <return\> - a return statement (e.g., return result;)

The program needs to read in srcML files (in XML) and build an internal representation of the AST as a tree data structure. When using XML this internal representation is typically called a Document Object Model (DOM). A set of classes defining the data structure (DOM) is in shared (ASTree.hpp and ASTree.cpp). This part of the project is partially implemented (i.e., the read and write work). The given code compiles and runs. The program currently is able to read in a srcML file and construct the internal tree representation. It can also write the code back out (minus the XML) from the internal tree representation. The task is to complete the implementation and build the instrumenter for the profiler.

The specification for the profiler is as follows:

- The program will take as input a list of files that are to be profiled. The first file in the list will be the main body.
- The program will instrument all the files to keep track of each function and statement executed in the program.
- The program will also instrument the main body with two additional parts. The first is a set of global profiling variables. Second, at the end of the main body the results of the profiling data will be printed to an output file (or the screen if none is supplied).
- Profile how many times each function or method in the supplied files is executed. Keep track of this by the filename, line number, and function name.
- Profile how many times each statement is executed. Keep track of this by filename and line number. Include all statements ending with a semicolon (e.g., assignments, function calls) and all statements within loops, if/else, and case statement.
- Do not count:

- break, return, goto, or throw statements
- declaration statements
- statements in for-loop specifications, for example, don't count the i=0, i==n, or ++i in `for (i=0; i==n; ++i)`
- conditions (but see challenge), that is, only count statements in the bodies of if-stmts or loop-stmts and not how many times the condition is executed

- Do not worry about following any formating style (indentation, etc.) for the inserted code.
- Output: For each file print out, ordered by line number, the counts for each line and function.

In short, the profiler program will read in source code and write out source code that has been instrumented. Then compile and run the instrumented version of the code to get the profile information. Below is a full example of the tool chain. First convert main.cpp into srcML. Then run the profiler on that XML file. This will produce a instrumented version of main.cpp called p-main.cpp. Finally, compile and run this program.

`srcml simple.cpp -o simple.cpp.xml`  
`./profiler simple.cpp.xml `  
`clang++ -Wall p-simple.cpp -c `  
`clang++ -Wall profile.cpp -c `  
`clang++ -Wall p-simple.o profile.o -o p-simple`  
`./p-simple`

```

2
Done
simple_cpp:
Line  Executed
14 search 1
19 1
28 main 1
32 1
33 1
35 1
36 1
```

**Requirements:**

- **Milestone 1** - 30%

- Implementation:

- Name the folder for this project **profiler**.
- READ the code given in ASTree.hpp/cpp, profile.hpp/cpp, and main.cpp under shared. You must be familiar with this code to complete the project. You are required to add code and comments to these files. You are free to modify them as necessary.
- The provided code works (compiles and runs) and the read/write are implemented.
- Implement the necessary 1) destructor, 2) copy constructor, 3) constant time swap, and 4) assignment operator for the AST class. There are comments pointing out which methods still need to be implemented.
- The code uses STL and you may use STL in the solution, including `std::string`.

- Testing:

- Test the copy constructor, destructor, swap, and assignment using the supplied function in main.cpp. It prints the object out in the function. Manually check to see if it the same output as printed out in the main. Use simple.cpp.xml as input. You can also us valgrind to check for memory leaks.
- Use the provided makefile: `make profiler`

- **Milestone 2** - 30%

- Implementation:

- Complete the following methods: mainHeader, mainReport, and fileHeader
- Read the code given in ASTree.hpp/cpp
- Read and use the provided profile ADT (profile.hpp/cpp). This is a simple ADT that uses the STL map data type. It is a map of (`string` X `int`). With the string being the function name and/or line number. The integer is the count of times that line/function is executed.
- To profile the program you will need to create a `profile` object for each file (as given on the command line) to keep track of statements and functions. These will be inserted as code into the main as global variable declarations. The main is the first file given in the input.
- All profile objects need to be declared in the main and for each additional file you will need to include profile.hpp and declare the file's profile object as external, for example `extern foo_cpp;`
- The profiler only needs to work on cpp files. Do not instrument header files (.h, .hpp).
- Implement the functionality to insert profile declarations into the main file (insertMainHeader). Also, insert the declaration lines into the other files (insertFileHeader) - see milestone 3 for an example. This is needed for milestone 3.
- Also, you will need to add statements to the end of the main to print out the profile data (insertMainReport). This should go just before the return. Assume there is only one return in the main. This report will print each item in the map (function or line number) followed by the counts. For example given the following main:

```

           //File main1.cpp
           #include <iostream>

           int main() {
              int i;
              i = 0;
              while (i < 10) {
                ++i;
                std::cout << i;
              }
              return 0;
            }
```

- The profiler will need to insert the following lines of code (in red):

```

           //File p-main1.cpp
           #include <iostream>

           #include "profile.hpp"
           profile main1_cpp("main1.cpp");

           int main() {
              int i;
              i = 0;
              while (i < 10) {
                ++i;
                std::cout << i;
              }
              std::cout << main1_cpp << std::endl;
              return 0;
            }
```

- Testing:

- Use simple.cpp (simple.cpp.xml) as a test case.
- Make sure insertion of the code works properly (manually inspect).
- The output (p-simple.cpp) should compile and run.

- **Milestone 3** - 40%

- Implementation:

- Complete the remaining methods: insertLineCount, insertFunctionCount
- For every function (i.e., free function, method, constructor, destructor), insert a line of code to update the corresponding file profile object given the function name and line number. The line number is used to provide a unquie map index for overloaded functions. This will add one to the corresponding map element. Insert this code as the first line in the function, right after the { is fine. Assume there are no nested functions.
- For every line of code, (i.e., expr_stmt, call) as defined above, add a line of code after it that updates the correct file profile object given the line number. Use the `__LINE__` macro for this. This macro returns an integer and you need to convert this value to a string for use in the profile ADT.
- ASSUME all loops and conditionals have a block. That is, no single line bodies. For example, there will always be a block after a loop as in `for (i=0; i==n; ++i) { x=x+1; }` versus no block as in `for (i=0; i==n; ++i) x=x+1;`.
- The profiler only needs to work on cpp files. Do not instrument header files (.h, .hpp).
- Send the profiler output for each input file to a new file. Prefix a "p-" to the begining of the orginal file name. For example: p-main.cpp or p-ASTree.cpp
- Running the following: `profiler main1.cpp.xml foo.cpp.xml` will result in final code will look something like the following for file p-main1.cpp:

```

           //File: p-main1.cpp
           #include <iostream>

           #include "profile.hpp"
           profile foo_cpp("foo.cpp");
           profile main1_cpp("main1.cpp");

           int main() { main1_cpp.count(__LINE__, "main");
              int i;
              i = 0;  main1_cpp.count(__LINE__);
              while (i < 10) {
                ++i;  main1_cpp.count(__LINE__);
                std::cout << i;  main1_cpp.count(__LINE__);
              }
              std::cout << foo_cpp << std::endl;
              std::cout << main1_cpp << std::endl;
              return 0;
            }
```

- And p-foo.cpp

```

           //File p-foo.cpp

           #include "profile.hpp"
           extern profile foo_cpp;

           int foo() { foo_cpp.count(__LINE__, "foo");
              int i;
              i = 0;  foo_cpp.count(__LINE__);
              return i;
            }
```

- Testing:

- The profiler application must be able to work with the provided source code, a sorting application.
- Run the application for all three algorithm and compare the profiles.
- ./sort -bs -sz 100 -od -osd
- The makefile can build the profiler, sort, and profiled sort (p-sort).

- **Challenge** - 10 pts extra credit

- Profile all conditionals.
- Count the number of times the conditional in a while, if, for, repeat, or switch is executed.
- For example, given the following code:

```

           i = 0;             //Line 1
           while (i < 10) {   //Line 2
              ++i;            //Line 3
           }
```

- If this code is run only one time, it will have Line 1 executing 1 time, Line 2 (the conditional) executing 11 times, and Line 3 executing 10 times.
- These should be stored by file and line number just as other statements.
- Hint: use operator&& or the coma operator (operator,).

- **Other Requirements:**

- You must have a separate specification file (.hpp), implementation file (.cpp), and main file.
- Your program will be graded on programming and commenting style as well as the implementation of your ADT.
- Include all source code files in svn.
- See the grading policy for other requirements.

---

URL: https://data-structures.cs.kent.edu/projects/proj4.html  
Last update: 04/09/2025 20:20:22 EST

---
