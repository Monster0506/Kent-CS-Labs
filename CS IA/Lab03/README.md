# Looping

## Lab Assignment

The assignment contains two parts

1. **Positive sum**. Study Create a project titled Lab3_Sum with a single file sum.cpp. Your program should ask the user for a sequence of numbers until the user inputs 0 (zero) and then the program should print the sum of postive numbers that the user input. Here are some example dialogs:

   Input sequence of integers (zero to stop):-4 -3 -20 10 45 -100 1 0
   The sum of postive numbers is: 56

   Input sequence of integers (zero to stop):-1 -3 -5 -7 8 10 0
   The sum of postive numbers is: 18

   Input sequence of integers (zero to stop):-3 -2 -1 1 2 3 0
   The sum of postive numbers is: 6

   You are not allowed to use functions, arrays or other constructs that we have not yet studied.

   **Hint:** You need to use iterate-and-keep-track idiom. while or do-while would be a good construct to use. Consider a single number in each iteration. In the while\-expression check if this number is not zero. If not -- proceed, if yes -- stop evaluation and print out the result. Declare a variable where your program will collect the sum of postive numbers. Make sure to initialize this variable. In the loop, with an if, check if the number is postive and, if yes, add it to the sum. Look at [this example](https://web.cs.kent.edu/~mbektic/Labs/Lab3/max.cpp) of selecting the maximum number. It is very similar to what you need to implement.

2. **Figures.** Create a project titled Lab3_Figures with a single file figures.cpp. Your program should ask the user for figure size and paint character and then print figures of user-supplied size and character as shown below. Here is an example dialog. User input is show in **bold**make sure to use a function for each shape and name the functions bob_saget, john_stamos, candace_bure, jodie_weetin, and dave_coulier

```
    Input figure size: **7**
    Input paint character: **+**

    +++++++
    +++++++
    +++++++
    +++++++
    +++++++
    +++++++
    +++++++


    +
     +
      +
       +
        +
         +
          +

          +
         +
        +
       +
      +
     +
    +

    +++++++
    +     +
    +     +
    +     +
    +     +
    +     +
    +++++++

    +     +
     +   +
      + +
       +
      + +
     +   +
    +     +
```

Note that your program has to work for an arbitrary integer, not just 7 and with an arbitrary character, not just +. You can use either while or for looping constructs.**Hints:** For each figure, you need to use two nested loops: the outer loop will iterate over rows (of characters) and the inner loop will print out the characters in a single row. The programming structure for all figures is similar. Study the code for the [odometer program](https://web.cs.kent.edu/~mbektic/Labs/Lab3/odometer.cpp). This program has nested loops which are very similar to what you need to implement.

I suggest you code and debug the first figure printout and then proceed to the next. The figure order is in the increasing difficulty.

In the second figure (the first diagonal line), you print a character when the row index is equal to the column index. That is, the loop variable of the outer loop should be present in the loop-expression of the inner loop. Consider the numbers of row and columns in a table. These numbers will be reflected by the loop variables:

| column index is red, row index is green | column 0 | column 1 | column 2 | column 3 | column 4 |
| :-------------------------------------: | :------: | :------: | :------: | :------: | :------: |
|                  row 0                  |    00    |    01    |    02    |    03    |    04    |
|                  row 1                  |    10    |    11    |    12    |    13    |    14    |
|                  row 2                  |    20    |    21    |    22    |    23    |    24    |
|                  row 3                  |    30    |    31    |    32    |    33    |    34    |
|                  row 4                  |    40    |    41    |    42    |    43    |    44    |

In the third figure, you print a character when the column index is the same as the figure size minus the row index minus one. To put another way: row plus column equals figure size minus one.

To code the hollow square, consider using a multiway if with the following logic:

1. If it is the first line - then print a character
2. else if it is the last line - then print a character
3. else if it is the first column - then print a character
4. else if it is the last column - then print a character
5. else print a space

The X is the combination of diagonal lines.

**Milestone:** implement part 1 (sum) of the assignment.

Make sure you program adheres to proper programming style. Submit your project to the subversion repository. Do not forget to verify your submission on the web.
