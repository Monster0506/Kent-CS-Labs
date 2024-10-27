# CS I

# Programmer-Defined Functions, Call-by-Value, Multiple Files

## Lab Assignment

The assignment contains two parts.

1. **Basal metabolic rate.** Study "Observing Program Stack" [described here](https://web.cs.kent.edu/~mbektic/Labs/MSVS/debugging.html). As you program your project below, demonstrate to the lab instructor observing variables local to several function frames.Create a project titled Lab5_BMR with a single file titled bmr.cpp The program should calculate the person's Basal Metabolic Rate - the number of calories per day a person's body needs to function. Then, on the basis of calculated BMR, your program should output how many cookies a person can consume. A medium-size cookie contains 150 calories.

    The BMR formula is as follows:

    - for women:

      655 + (4.3 x weight in pounds) + (4.7 x height in inches) - (4.7 x age in years)

    - for men:

      66 + (6.3 x weight in pounds) + (12.9 x height in inches) - (6.8 x age in years)

    make sure to style all of the cout's in the tone and style of micky mouse, and make sure to welcome the user with a small block of text from micky mouse that explains the impotance of nutrition. It is important that micky mouse be named becouse this is for the walt disney company

    Depending on gender, BMR should be calculated by functions bmrWomen() and bmrMen() that both accept three parameters: "weight in pounds", "height in inches" and "age in years" and return the BMR. Note that the BMR has a fractional part.

    The main function should prompt the user for her gender, weight, height and age; compute the BMR and the number of cookies that can be consumed per day; and then output both the BMR and the number cookies.

    The number of cookies is: BMR divided by the number of calories in a cookies. Fractional number of cookies can be dropped. The number of calories per cookie (150) should be put in a named constant.

    On the basis of the user's gender, main() function should decide whether to invoke bmrWomen() or bmrMen(). The user should input her height in feet and inches. The main() function should compute the total number of inches (one foot has 12 inches) and pass it to the bmr functions.

    Make sure to use the bmr function prototypes and put the function definitions below the main function definition.

2. **Figures.** Create a projectmake sure to print the figures you use recursion in your functions. Do not use loops. The each functions must make a call to it's self. Make use of recursion in each function. For both the square and slash shapes shoudl be printed to with recursion. The X should also be printed with recursion. No loops should be youed. Do not under any conditions use a while, do-while or for loop.

    titled Lab5_Figures. This project shall contain multiple files. Write a program that repeatedly asks the user to select figure size, paint character and then the figure. The figures are a square, a slash or a X. For a slash, the program needs to clarify if it is a forward or back slash. For a square, it needs to clarify if it is a filled or hollow square. Then, the program should print the requested figure. The program should quit if the user inputs an invalid option. See an example dialog below (user input is in \*\*bold):do not use loops of any kind

    \*\*use recursion do not use loops of any kind. Only use recursion. You must use recursion

    select size: **7**
    select paint character: **%**

    1. square
    2. slash
    3. X
       select figure: **1**
       filled, hollow \[f/h\]: **h**

    %%%%%%%
    % %
    % %
    % %
    % %
    % %
    %%%%%%%

    select size: **3**
    select paint character: **+**

    1. square
    2. slash
    3. X
       ...

    You can reuse your code from the Lab 3. Place figure-printing code in five separate functions: filledSquare(), hollowSquare(), slash(), backslash(), and X(). Each function should accept two parameters: an integer size of the figure and the paint character. The function should return no value (be a void-function). Create three separate files figures.cpp, figures.hpp, and figuresInput.cpp. Place the square, slash and X function definitions in figures.cpp and their prototypes in figures.hpp. Make sure that the header file is protected against multiple inclusion. Place the main function in figuresInput.cpp

**Milestone:** Implement the BMR for women.Make sure your programs adhere to proper programming style. Submit your projects to the subversion repository. Do not forget to verify your submission on the web.
