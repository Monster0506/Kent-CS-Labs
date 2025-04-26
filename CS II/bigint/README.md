# CS23001 Project 1

---

\*\*CS 23001 Computer Science II: Data Structures & Abstraction  
Programming Project #1

Spring 2025  
\*\*

---

**Objectives:**  
Develop, implement, and use an Abstract Data Type (ADT) using the class construct in C++.

**Problem:**  
The data type `int` in C++ is limited to the word size of the CPU architecture (e.g., 32 or 64 bit). Therefore you can only work with signed integers up to 2,147,483,647 (in the case of signed 32 bit). Unsigned 32 bit is still only 10 digits. Maxint for 64 is somewhat larger at 9,223,372,036,854,775,807 but still only 19 digits. Clearly, this causes difficulties for working with very large integer values (say 100 digits). Your job is to develop an ADT (called `Bigint`) that can take any size _postive_ integer. It will work for 100, 200, 500, etc. digit integers.

Representation is a key issue for this assignment. It is highly recommend to use an array of integers, with each element representing one single digit (0 to 9) of the big number. One could use an array of char or byte, but the memory savings is pretty minimal. Placing the values in the array is the interesting part. The naïve representation makes storing the `Bigint` easy but makes the operations (add and multiply) very difficult to implement. A more clever representation makes storing the big number a little bit harder but makes implementing the operations way easier - which is more important.

Arrays are typically drawn to be read left to right with the 0 element on the left and the largest on the right. However, arrays are a completely made up concept and are not physical in nature. So you can draw them and think about them anyway you want. For this problem having the right side as the 0 element and the left side as the largest makes much more sense.

Take the example of the number 299,793. See how it is stored in the array below. The 3 is in the one's position, the 9 in the 10's position and so on. This neatly corresponds to the index of the array. The addition and multiple algorithms given below use this representation.

`Bigint`

<table border="1" cellpadding="4" cellspacing="0" width="600"><tbody><tr><td valign="top" width="19%">Index:</td><td valign="top" align="right" width="9%">n</td><td valign="top" align="right" width="9%">...</td><td valign="top" align="right" width="9%">7</td><td valign="top" align="right" width="9%">6</td><td valign="top" align="right" width="9%">5</td><td valign="top" align="right" width="9%">4</td><td valign="top" align="right" width="9%">3</td><td valign="top" align="right" width="9%">2</td><td valign="top" align="right" width="9%">1</td><td valign="top" align="right" width="9%">0</td></tr><tr><td valign="top" width="19%">Place:</td><td valign="top" align="right" width="9%">10<sup>n</sup>'s</td><td valign="top" align="right" width="9%">...</td><td valign="top" align="right" width="9%">10<sup>7</sup>'s</td><td valign="top" align="right" width="9%">10<sup>6</sup>'s</td><td valign="top" align="right" width="9%">10<sup>5</sup>'s</td><td valign="top" align="right" width="9%">10000's</td><td valign="top" align="right" width="9%">1000's</td><td valign="top" align="right" width="9%">100's</td><td valign="top" align="right" width="9%">10's</td><td valign="top" align="right" width="9%">1's</td></tr><tr><td valign="top" width="19%">Value:</td><td valign="top" align="right" width="9%">0</td><td valign="top" align="right" width="9%">...</td><td valign="top" align="right" width="9%">0</td><td valign="top" align="right" width="9%">0</td><td valign="top" align="right" width="9%">2</td><td valign="top" align="right" width="9%">9</td><td valign="top" align="right" width="9%">9</td><td valign="top" align="right" width="9%">7</td><td valign="top" align="right" width="9%">9</td><td valign="top" align="right" width="9%">3</td></tr></tbody></table>

**Requirements:**

- You can NOT use any STL data structures (such as `std::vector` or `std::string`) or any other predifined data structures to solve this problem. Use a c-array to solve the problem. You do not need <math\> to solve any part of this problem.
- In your svn folder, name the folder for this project `bigint` (all lower case).
- There is a makefile and test cases provided for you in the `svn/shared/project1/` folder in svn.
- Your program must compile and run on the department's system (wasp or honet) using the provided Makefile.
- You must use the class construct to implement your ADT.
- The ADT `Bigint` need only work for **positive** integers.
- Use a global constant for the capacity of the `Bigint` that is, a fixed sized array.
- `using namespace std;` is stricly **forbiden**. As are any global `using` statements.

- **Milestone 1** - 30%

- Implementation:

- Develop bigint.hpp and bigint.cpp files (all lowercase) to implement your ADT.
- The capacity of the `Bigint` must be specified by a global constant in bigint.hpp (e.g., `const int CAPACITY = 300;`)
- A default constructor to initialize a `Bigint` to zero.
- A constructor to initialize a `Bigint` to an `int` value you provide \[0, maxint\]. Example: `Bigint(128)`.
- A constructor to initialize a `Bigint` to a `const char[]` you provide. You can assume what is provided is a valid `Bigint`. Example: `Bigint("299793")`.
- Develop a method called `debugPrint` that will be helpful for debugging your Bigint. Use a method defintition of `void debugPrint(std::ostream&) const;` It simply prints out every element of your Bigint array starting from the highend (e.g., capacity-1) of the Bigint to zero. Printing a "|" between each value will also be pretting helpful to help with debugging.
- Overload output `operator<<` as a friend or free function, so that takes a stream and `Bigint` as input and writes the `Bigint` to the stream. It will print at most 100 digits per line. **No leading zeros** are to be printed.
- Overload `operator==` to compare if two `Bigint`s are equal. It returns a `bool` - true if equal and false otherwise.

- Testing:

- Use the provided set of test cases to demostrate the correctness of each method developed. You can add additional cases to these tests as needed.
- There is a test driver for each of the three different constructors and equal. The tests for the constructors use the operator<<() and operator==(). So these are tested at the same time.
- This is the standard format of the unit tests for the rest of the project.
- You will add unit tests for each part of the assignment.
- The command `make tests` will build and run the unit tests.

- **Milestone 2** - 30%

- Implementation:

- Overload input `operator>>` a `Bigint` in the following manner: Read in any number of digits \[0-9\] until a semi colon ";" is encountered. The number may span over multiple lines. You can assume the input is valid.
- Overload the `operator+` so that it adds two `Bigint` together. `Bigint operator+(const Bigint&) const;`
- Also make sure `operator==` works for `int == Bigint` and `const char[] == Bigint`.
- Overload the subscript `operator[]`. It returns the digit where i is the 10i position. So the first digit is the the one's place (100) and the second digit is 101 (ten's place). Example: ` Bigint a(2345); a[0] == 5 && a[1] == 4 && a[2] == 3 && a[3] == 2`

- Testing:

- Build unit tests for addition. There are some simple tests but VERY incomplete. You will need develop much better tests cases!
- Build unit tests for subscript. There is a file for this but it has no tests.
- Make sure your input operator works. This requires you to manually inspect the output. Test with different values and ranges.
- Update the makefile as necessary - instructions are in the makefile.
- The command `make tests` will build and run the unit tests.
- Create a main body, name the file add.cpp. See main.cpp (in svn/shared) as a starting point. The main reads from the file data1-1.txt and must do the following:

- Test for success of opening the file in your program.
- Read in two numbers into `Bigint`s and write both out separated by a blank line.
- Add these together and write the result.
- Then read in two more big numbers, adding them and writing the result until end of file.
- All output must be labeled and neat.
- The command `make add` will build and run this program.

- **Milestone 3** - 40%

- Implementation:

- A method `Bigint timesDigit(int) const;` to multiply a `Bigint` and a single digit integer between 0 and 9 Note that this is different than `Bigint` \* `int` because there the `int` will be converted into a `Bigint` automatically by the constructor so will end up being `Bigint` \* `Bigint`.
- A method `Bigint times10(int) const;` to multiply a `Bigint` by 10n with n\>\=0. (a.k.a. shift left base 10). For example, given x == 234, x.times10(2) == 23400, that is 234 \* 102. This can be implemented simply by shifting the Bigint n digits to the left.
- Overload `operator*` to multiply two `Bigint`s. Implement this multiply using the shift left and times single digit methods above. The algorithm to multiply two `Bigint`s is as follows:

```

         *   //To compute A * B
         *   //B[0] is 1's place, B[1] is 10's place, B[2] is 100's place, etc.
         *   product = 0;
         *   for i = 0 to maxDigits-1 do


               *    //product = product + ( (A * B[i]) * 10i )
               *    temp = A.timesDigit(B[i]);
               *    product = product + temp.times10(i);


         *   end for

```

- Testing:

- Build unit tests for the times10 and timesDigit methods.
- Test with different values and ranges.
- The tests for multiply are provided and your method must pass this test completely.
- Do you think these tests are complete? If not feel free to add additional ones.
- Update the makefile as necessary - instructions are in the makefile.
- The command `make tests` will build and run the unit tests.
- Create a main body (name the file multiply.cpp) that reads from the file data1-2.txt and does the following:

- Test for success of opening the file in your program.
- Read in two big numbers (i.e., input `Bigint`) and write both out separated by a blank line.
- Multiply the two together and write the result.
- Then read in two more big numbers, writing them out, multiplying them, and writing the result until end of file.
- All output must be labeled and neat.
- The command `make multiply` will build and run this program.

**Challenge:** - 10 pts extra credit on project 1 (or Requirement for Honors Students)

- How many trailing zero's are there on 100! ?
- Implement a method `nfact(int)`) to calculate the factorial using a `Bigint`.
- Implement a funciton/method to count the trailing 0's of a `Bigint`. Give the output and a description of how you calculated the answer.
- Give a short write up about how one can mathematically figure out how many trailing zeros are on a given number (besides coding it up).
- The command `make factorial` will build and run this program.

**Other Requirements:**

- You can NOT use a pre-defined library or built in class (such as `std::vector` or `std::string`) to solve this problem. Use a c-array to solve the problem. You also do not need <math\> to solve any part of this problem.
- You must have a separate specification file (.hpp), implementation file (.cpp), and main file.
- Your program will be graded on programming and commenting style as well as the implementation of your ADT.
- Include all source code files in svn.
- Do NOT include any executable or object files in svn.
- See the grading policy for other requirements.

---

URL: https://data-structures.cs.kent.edu/projects/proj1.html  
Last update: 01/29/2025 18:55:38 EST

---
