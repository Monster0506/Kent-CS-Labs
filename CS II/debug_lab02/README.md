# CS2 Lab - Debugging II

# Lab - Debugging II

## Objectives

- Debug a small application
- Find and fix all the bugs
- Go over the next part of your project

## Discussion

Basic Debugging Tips:

- Compile the program

- If there are compiler errors, start by trying to fix the first (top-most) error.
- Read the error message and examine the code at the line number it gives you.
- Fix any warnings after fixing errors

- Run the program
- Use debug statements (`std::cerr`) to:

- Check variable values
- Determine the flow of the program

- Be systematic and fix ONE bug at a time.
- Re-compile and run the program after each potential fix.

## Setup

We need to:

1.  Copy the _debug_lab2_ directory from _shared_ into your _cs23001_ folder

## Assignment

The program you've been given, `pop_growth.cpp` has multiple bugs. You may **NOT** use a third-party debugging tool (i.e., **NO** Visual Studio).

- This program is designed to calculate the estimated population growth of a university over 5 years.
- Users are prompted for the name of the university, the current population, and the percentage of growth.
- Fix all of the bug(s) and re-run the program to confirm that you've fixed them all.

Example input and output:

```
$ make pop
$ ./pop
Enter the name of the university
Kent State University
What is the current population? 10000
What is the rate of growth? (e.g., for 10% enter 10) 20

Year  New Population
1     12000
2     14400
3     17280
4     20736
5     24883

Final population of Kent State University is 24883
Done? (Y/N) y
Exiting...
```

Remember that you can run this multiple times:

```
$ make pop
$ ./pop
Enter the name of the university
Kent
What is the current population? 5678
What is the rate of growth? (e.g., for 10% enter 10) 5

Year  New Population
1     5961
2     6259
3     6571
4     6899
5     7243

Final population of Kent is 7243
Done? (Y/N) N
Starting again
------------------------------
What is the current population? 123
What is the rate of growth? (e.g., for 10% enter 10) 8

Year  New Population
1     132
2     142
3     153
4     165
5     178

Final population of Kent is 178
Done? (Y/N) y
Exiting...
```

Don't forget about errors:

```
$ make pop
$ ./pop
Enter the name of the university
The Venture Bros. University!
What is the current population? -1
./pop: Invalid Input Error!
```

```
$ make pop
$ ./pop
Enter the name of the university
OSU
What is the current population? 7896
What is the rate of growth? (e.g., for 10% enter 10) foobar
./pop: Invalid Input Error!
```

```
$ make pop
$ ./pop
Enter the name of the university
MIT
What is the current population? 9000
What is the rate of growth? (e.g., for 10% enter 10) 15

Year  New Population
1     10350
2     11902
3     13687
4     15740
5     18101

Final population of MIT is 18101
Done? (Y/N) q
./pop: Invalid input
The program will exit
------------------------------
```

## Requirements

The following should be true when you are done, **NAMES MUST MATCH EXACTLY**:

- You have copied the _debug_lab2_ folder into your _cs23001_.
- In the directory _debug_lab2_ you have the following files:

- The fixed `pop_growth.cpp` file

- There are **NO** executables in the repository.
- Your program compiles, runs, and performs as specified, with any bug(s) fixed.
- Your program follows the [General Program Requirements](https://data-structures.cs.kent.edu/labs/Info/general_prog_req.html).

---

URL: https://data-structures.cs.kent.edu/labs/Lab12  
Last update: 11/07/2024 01:30:13 EST

---
