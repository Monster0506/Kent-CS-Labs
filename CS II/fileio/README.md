# CS2 Lab - File I/O

# Lab - File I/O

---

## Objectives

- Learn and understand how file I/O works in C++
- Learn how to overload the `>>` operator
- Discuss the next part of Project 1

---

## Discussion

First go over doing File I/O in C++. We will use the _Bigint_ data files as examples.

You will need to include the following to do file I/O. `fstream` is for file I/O streams.

```

#include <iostream>
#include <fstream>

int main () {
    //Creates a stream inFile that points to a file.
    //Opens the file data1-1.txt for input (reading).
    std::ifstream inFile("data1.txt");

    // Process file
    //

    infile.close(); //Need to close file
}
```

After opening the file, we should check to see if the file is opened properly. If not, we deal with the error. The file may not exist and hence, can not be open properly.

```

if (!inFile.is_open()) {
    std::cout << "Error: Unable to open file";
    // exit or return
}
```

Now that the we know the file is properly open, it can be read from. Let us go over how `get()` works. It is the most simple form of input for C++. It reads one character at a time.

```

    char ch;
    // ch is passed by reference and assigned a SINGLE character
    inFile.get(ch);
```

The stream `inFile` is basically a pointer to the location in the file to read next. `get(ch)` reads the next single character from the stream `inFile` and assigns it to `ch`. Also, the stream now points to the next character to read in the file.

However, you maybe at the end of the file (EOF), and there is nothing to read. This is a problem and can cause errors and infinite loops. The `eof` method on the stream checks the state of the stream. Returns if it is at the end of file or not.

ALWAYS check for end of file before EVERY read.

Normally we loop on not end of file and use `get` to read the contents of the file.

Below is an example of using `eof()` with `get`. It will read each character from a file and print it out. Thus making an exact copy of the file.

```

#include <iostream>
#include <fstream>

int main() {
    std::ifstream inFile("data1.txt");
    if (!inFile.is_open()) {
        std::cout  << "Unable to open file\n";
        return 1;
    }

    char ch;
    if (!inFile.eof()) inFile.get(ch);  //Read the first character in the file
    while (!inFile.eof()) {             //It may now be end of file
        std::cout << ch;                //Print out the character
        inFile.get(ch);                 //Read the next character
    }
    std::cout << std::endl;
    inFile.close();
    return 0;
}
```

Try the above code and get it working.

Why are we doing a read before the loop?

If a read fails (e.g., at the end of the file) it does not modify `ch` and end of file is true.

What will happen if we did not do a read before the loop and in the loop did a read than print?

Let us now examine the behavior of the `>>` operator for reading characters from a file.

1.  It skips all leading whitespace
2.  Reads one character
3.  Unlike `get()` in that whitespace is always skipped

Whitespace is skipped when using `>>`. Whitespace characters are space (`' '`), tab (`'\t'`), new line (`'\n'`), carriage return (`'\r'`) and end of file.

```

   char ch;
   while (!inFile.eof()) {
     inFile.get(ch)
     std::cout << ch;
   }
```

Try it! Edit the loop above with the `>>` operator version. **_IMPORTANT:_** Whitespace is skipped with `>>` operator, Whitespace is **_NOT_** skipped when using `get()`.

Notes:

- When you open a file, the stream is a pointer to where you currently are in the file. So every time you read from the file, the pointer is moved to what will be read next.
- If you close and re-open the file, the pointer points to the beginning of the file again. This means you should only close a file when you are done reading.

---

## Setup

Need to:

1.  Create a directory called `fileio` in your `cs23001` svn folder.
2.  Copy the provided data and code files. These will be in the shared/labs/ folder. The instructors will give the location/name of the file in lab.
3.  There is a file called `fileio.cpp`, which will contain the code for this lab assignment.

---

## UNIX Quiz

As a part of your lab assignment, you must complete a quiz in Canvas. This quiz will cover what you learned in the previous lab about UNIX system commands.

You have the entire lab to complete the quiz. You may not complete this quiz outside of your lab.

---

## Assignment

Write code to solve a set of different reading tasks. Use the provided `fileio.cpp` as a starting point. Compile the code as follows:

`clang++ -Wall fileio.cpp -o fileio`

This will result in an executable called fileio. The program takes a file name as input. Use the following to run the program:

`./fileio data1.txt`

### Part 1

Count all the characters in a file, including the end of file. Use `get()`.

- Print each character with its index one per line.
- At the end print the total number of character in the file.

Example input file contents:

```
Hello Jan
```

Example output:

```
1: H
2: e
3: l
4: l
5: o
6:
7: J
8: a
9: n
Total: 9
```

### Part 2

Count all the non-whitespace characters in a file. Use `>>`.

- Print each character with its index one per line.
- At the end print the total number of non-whitespace character in the file.

Example input file contents:

```
Hello Jan
```

Example output:

```
1: H
2: e
3: l
4: l
5: o
6: J
7: a
8: n
Total: 8
```

### Part 3

Count the number of words a file. Use `>>`. A word is any sequence of characters separated by whitespace.

- Print word with its count one per line.
- At the end print the total number words in the file.
- Read in a char\[\] using `>>`.
- Hint: You can use char\[\] exactly like a char with `>>`. Make sure you allocate enough space in the array.

Example input file contents:

```
Hello Jan,
how are you today?
```

Example output:

```
1: Hello
2: Jan,
3: how
4: are
5: you
6: today?
Total: 6
```

### Part 4

Count the number of lines a file. Use `getline()`.

- Print line with its count one per line.
- At the end print the total number lines in the file.
- `getline()` takes a char\[\] and int size as input. Example: `inFile.getline(line, 120);`
- Hint: `getline()` works very similarly to `get()`.

Example input file contents:

```
Hello Jan,
how are you today?
```

Example output:

```
1: Hello Jan,
2: how are you today?
Total: 2
```

### Part 5

Read a sentinel value (integer) from a file (on first line), than read that many lines of data (one word per line).

- Use data3.txt
- Create a new program called fileio2.cpp that solves this problem.
- Print line count read in to verify.
- Print the contents of each line, one per line with the count.
- Read in each line as a char\[\] using `>>`. It will be one word per line.
- Is there anything wrong with the data file? How can you fix this problem in your **program**? You can not change the data file!

---

## Requirements

The following should be true when you are done, **NAMES MUST MATCH EXACTLY**:

- In your _cs23001_ directory you have created a directory named _fileio_.
- In the directory _fileio_ you have the following files:

- `fileio.cpp`
- `fileio2.cpp`
- The provided input data files

- There are **NO** executables in the repository.
- Your program compiles, runs, and performs as specified.
- Your program follows the [General Program Requirements](https://data-structures.cs.kent.edu/labs/Info/general_prog_req.html).

---

URL: https://data-structures.cs.kent.edu/labs/Lab4  
Last update: 02/03/2025 22:29:17 EST

---
