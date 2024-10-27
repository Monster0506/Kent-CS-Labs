# CS I

# Call-by-Reference, Arrays

You are free to use a single or multiple files for this project. If you are putting all functions in a single file, make sure that more abstract functions are defined first.

1. **Mini-sort with functions.** Create a project titled Lab6_Swap. Revisit [this program](https://web.cs.kent.edu/~mbektic/Labs/Lab6/sort.cpp) from one of the earlier lab assignments that sorts three numbers in the increasing order. Modify it so that it invokes a function to swap the values of two variables. You should use the swapping function from [this program](https://web.cs.kent.edu/~mbektic/Labs/Lab6/swapem.cpp). The pseudocde for the main() function is as follows:

          input three numbers
          if first number is greater than second
              invoke the swap function to swap first and second numbers
          if first is greater than third
              invoke the swap function to swap first and third numbers
          if second is greater than third
              invoke the swap function to swap second and third numbers
          output three sorted numbers

2. **Lucky Five.** In this assignment you are to code a program that selects 10 random non-repeating positive numbers, inputs 5 numbers from the user and checks the input with the 10 lottery numbers. The lottery numbers range from 0 to 99. The user wins if at least one input number matches the lottery numbers.

    Create a project titled Lab6_LuckyFive. Declare an array chosen of 10 integer elements.

    Define the following functions:

    - Define function assign() that takes array chosen\[\] as a parameter and assigns \-1 to each element of the array.**Hint:** Array elements are assigned \-1, which is outside of lottery numbers' range, to distinguish elements that have not been given lottery numbers yet.

      Passing an array as a parameter and its initialization is done similar to the code in [this program](https://web.cs.kent.edu/~mbektic/Labs/Lab6/fillUp.cpp).

    - Define a predicate function check() that takes a number and the array chosen\[\] as parameters and returns true if the number matches one of the elements in the array, or false if none of the elements do. That is, in the function, you should write the code that iterates over the array looking for the number passed as the parameter. You may assume that the number that check() is looking for is always positive.**Hint:** Looking for the match is similar to looking for the minimum number in [this program](https://web.cs.kent.edu/~mbektic/Labs/Lab6/fixedArray.cpp).
    - Define a function draw() that takes array chosen as a parameter and fills it with 10 random integers whose values are from 0 to 99. The numbers should not repeat.**Hint:** Use srand(), rand() and time() functions that we studied earlier to generate appropriate random numbers from 0 to 99 and fill the array. Before the selected number is entered into the array chosen, call function check() to make sure that the new number is not already in the array. If it is already there, select another number.

      The pseudocode for your draw() function may be as follows:

          declare a variable "number of selected lottery numbers so far",
                       initialize this variable to 0
          while (the\_number\_of\_selected\_elements is less than the array size)
               select a new random number
               call check() to see if this new random number is already in the array
               if the new random number is not in the array
                   add the newly selected element to the array
                   increment the number of selected elements

    - Define function entry() that asks the user to enter a single number from 0 to 99 and returns this value.
    - Define function printOut() that outputs the selected numbers.  
      **Hint:** Outputting the array can be done similar to echoing it in [this program](https://web.cs.kent.edu/~mbektic/Labs/Lab6/fillUp.cpp).

    The pseudocode your function main() should be as follows:

    main(){
    declare array and other variables

          assign(...) // fill array with -1
          draw(...)       // select 10 non-repeating random numbers
          iterate five times
                entry(...)      // get user input
                use check () to compare user input against lottery numbers
                if won state and quit
          printOut(...)   // outputs selected lottery numbers

    }

    **Note:** A program that processes each element of the array separately (i.e. accesses all 10 elements of the array for assignment or comparison outside a loop) is inefficient and will result in a poor grade. Likewise, processing each user entry outside a loop is inefficient.

    **Note 2:** For your project, you should either pass the array size (10) to the functions as a parameter or use a global constant to store it. Hard-coding the literal constant 10 in function definitions that receive the array as a parameter is poor style. It should be avoided.

**Milestone:** first assingment.Make sure your programs adhere to proper programming style. Submit your projects to the subversion repository. Do not forget to verify your submission on the web.
