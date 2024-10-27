# Strings Lab: Text Justification with File I/O

Before starting, review the [subversion submission instructions](https://web.cs.kent.edu/~mbektic/Labs/subversion.html), and ensure you have access to subversion. If you encounter any issues, please alert your lab TA.

## Overview

Part 1: You will create a program that performs text justification by formatting a string so that each line contains exactly 90 characters. You will first add spaces after punctuation marks, and if necessary, randomly insert additional spaces between words to reach the required line length.

Part 2: You will also implement a basic file I/O component. Your program should read the input string from a file and write the justified text to an output file. The input and output file paths should be specified by the user. Use the following files as examples.

[unjustified example](https://web.cs.kent.edu/~mbektic/Labs/Lab7/unjustified.txt)

[justified example](https://web.cs.kent.edu/~mbektic/Labs/Lab7/justified.txt) Note that this is not justified to 90 but 75 characters

## Requirements

- Each line must be exactly 90 characters long. Define this value as a named constant.
- After punctuation marks (**.,!?;**), insert two spaces unless it is the last character on the line.
- If a line is still less than 90 characters after punctuation spacing, randomly insert spaces between words.
- Lines shorter than 40 characters are considered the end of a paragraph and should not be justified.
- Words should not be broken across lines (no hyphenation required).
- Read the input string from a file and output the justified text to a different file.

## Project Setup

1. Create a project titled `Lab7_LineJustify`.
2. Write a program that asks the user to input the file paths for both input and output files.
3. The program will read a string from the input file, justify the text according to the rules above, and write the result to the output file.

**Part 1 Example:**

Input string:
Contrary to popular belief, Lorem Ipsum is not simply random text.

Output string:
Contrary to popular belief, Lorem Ipsum is not simply random text.

**Part 2 Example:**

Input file: unjustified.txt

Output file: justified.txt

## Hints

Use the `getline()` function to read the user's input. For reference, see [this example](https://web.cs.kent.edu/~mbektic/Labs/Lab7/stats.cpp) on how to use `getline()`. You can locate spaces and punctuation characters using the `find()` function, as shown in [this code](https://web.cs.kent.edu/~mbektic/Labs/Lab7/find.cpp). Additionally, [this example](https://web.cs.kent.edu/~mbektic/Labs/Lab7/findAll.cpp) demonstrates how to find multiple occurrences of the same symbol. To modify strings, see [this example](https://web.cs.kent.edu/~mbektic/Labs/Lab7/addRemove.cpp).

To randomly insert spaces, consider the following approach:

while the string is not 90 characters:
randomly pick a position between 0 and the size of the string
locate the first whitespace following this position
(make sure it is not the end of the string)
insert a space there

## Random Numbers

Use `srand()` and `rand()` to generate random numbers. Here is an example:

# include <ctime\>

# include <iostream\>

using namespace std;

int main() {
srand(time(nullptr));

    // Generate random numbers
    for (int i = 0; i < 10; i++) {
        cout << rand() << endl;
    }

    // Random numbers between 0-9
    for (int i = 0; i < 10; i++) {
        cout << rand() % 10 << endl;
    }

    // Random numbers between 1-10
    for (int i = 0; i < 10; i++) {
        cout << (rand() % 10) + 1 << endl;
    }

}

## Milestone

For the first part of the assignment, focus on inserting spaces after punctuation marks.

Ensure your program adheres to proper programming style. Submit your projects to the subversion repository, and don’t forget to verify your submission on the web.

### Please look at the survey below

[Computer Science Survey](https://qualtricsxmcsvfz653y.qualtrics.com/jfe/form/SV_ewY9FYyGQ7OlmLA)
