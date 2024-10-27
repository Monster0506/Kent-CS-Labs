# Branching

## Lab Assignment

The assignment contains two parts.

1.  **Mini sort.** Study [tracing a program](https://web.cs.kent.edu/~mbektic/Labs/MSVS/debugging.html). Create a project titled Lab2_MiniSort. Cut and paste [this example program](https://web.cs.kent.edu/~mbektic/Labs/Lab2/sort.cpp) into your project. The program attempts to sort three integer numbers in the increasing order. However, it is incomplete. For example, it does not work for this input 3 2 1 . Debug the program. Demonstrate program tracing to the lab instructor.**Hint:** to correct the program you need to add another swapping of values between variables one and two.

    Submit the corrected program to the subversion repository.

2.  **Tax on Salary.** Create a project Lab2_tax. Company ABC has several different types of employees. Each employee has an assigned employee code (d,f,h,o). This employee code determines how taxes are withheld from their pay, i.e. d could be domestic while f could be forign. The amount to withhold as a percent earned is shown below

    | percent of salary to hold | employee code |
    | ------------------------- | ------------- |
    | 15%                       | d             |
    | 20%                       | f             |
    | 60%                       | h             |
    | 65%                       | o             |

    Create a program that as input takes the total earned by an employee and their employee code, then outputs the amount to withhold from their paycheck and their take home. The default case should be to print an error, "unknown employee code: " and then the code entered example,

    ```

       employee earnings: 1000
       employee code: d
       Amount to withhold: 150
       Take Home: 850

    ```

    error example,

    ```

       employee earnings: 1000
       employee code: a
       unknown employee code: a

    ```

    You may assume that the user will always enter the employee code as a lower case, 'd' never 'D'  
    You do not need to round to the nearest cent, the below example is ok

    ```

          employee earnings: 99.99
          employee code:f
          Amount to withhold: 19.997
          Take Home: 79.993

    ```

    You are not allowed to use the concepts, such as looping or functions, that we have not studied. Please use a switch statement not a multiway if

**Milestone:** implement part 1 (Mini sort) of the assignment.

Make sure you program adheres to proper programming style. Submit your project to the subversion repository. Do not forget to verify your submission on the web.
