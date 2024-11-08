# Pointers, Dynamic Memory Allocation

# Pointers, Dynamic Memory Allocation

In this assignment, you are to implement a program to help a collector of double numbers. He likes doubles and goes on field trips collecting them. However, he does not want to have more than one specimen of the same number in his list. He is somewhat absent minded and occasionally tries to add a number to his list even though he already has it. Your program will help him make sure that he does not have duplicates.

## Assignments

1. **Test list.** Create a project titled Lab10_TestList. In the project, you should use the functions prototyped in [this header file](https://web.cs.kent.edu/~mbektic/Labs/Lab10/list.hpp). You should place the functions you implement in a file named list.cpp. Your code should work with [this test file](https://web.cs.kent.edu/~mbektic/Labs/Lab10/testList.cpp) The functions to be implemented are as follows:

    - output() takes the pointer to the array and its size and prints the arrays' contents.
    - check() takes the pointer to the array and a number and checks if the number is in the array. If the number is in the array, returns the index of the element of the array holding the number. Otherwise, returns -1.
    - addNumber() takes a pointer to the array and adds a number to the array if the number is not already there.

      Use check() to check if the number is already present in the array.

      If yes, no further actions are required. If the number is not present, it needs to be added. The array cannot be enlarged to accommodate the number. Instead, this function needs to allocate a new array whose size is one more than the size of the old array, copy the contents of the old array to the new one, include the new number, deallocate the old array and then assign the address of the new array back to the original pointer.Note that since the pointer is passed by reference, the call to this function results in effectively "enlarging" the array pointed to by the pointer.

    - removeNumber() takes a pointer to the array, a number, and removes the number if it is present in the array. If the number is removed, the array shrinks.

      Again, use check() to check if the number is present in the array. If the number is not present, no further actions are required. If the number is present, then the function should allocate a new array of smaller size and then copy all the numbers to it, except the one that needs to be erased. After copying is done, deallocate the old array and update the array pointer to point to the new array.

      Copying and removing one element may be done in a single for-loop. Here is a pseudocode for the solution:

           create a boolean variable "found", set it to false
           iterate over elements in the old array,
               if old array element equals to the number to be removed then
                   set found to true
               else
                   if not found then
                       copy old array element to the new array element
                    else // found
                       copy old array element to the new array
                       element with index one less than old array's
                       (move them to the left)

    **Hint:** double \*p=new double\[0\]; works correctly: returns a pointer to zero-size array (array with no elements). This allows to avoid treating the array of size zero in the above functions as a special case.

2. **Number list.** Create a project titled Lab10_List. Write a program that allows the user to add a double number to a list or remove a double number from the list. After the operation, the contents of the list should be printed.The user may enter the number twice, in which case, the program should inform that it is a duplicate and the duplicate number should not be entered. The user may request to remove the number that is not in the list, in which case, the program should inform the user and remove nothing.

    Here is an example program dialog:

    enter operation \[a/r/q\] and number: a 5.0
    your numbers: 5
    enter operation \[a/r/q\] and number: a 8.0
    your numbers: 5 8
    enter operation \[a/r/q\] and number: a 8.0
    duplicate!
    your numbers: 5 8
    enter operation \[a/r/q\] and number: r 8.0
    your numbers: 5
    enter operation \[a/r/q\] and number: r 10.0
    not present!
    your numbers: 5
    enter operation \[a/r/q\] and number: a 3.3
    your numbers: 5 3.3
    enter operation \[a/r/q\] and number: a 12.2
    your numbers: 5 3.3 12.2
    enter operation \[a/r/q\] and number: q

    The size of the user input can be arbitrarily large. For this program, to accommodate user input, you need to implement an array of doubles whose size varies as necessary. The numbers in the array should not be sorted.

**Milestone:** implement functions output() and check().

Make sure your programs adhere to proper programming style. Submit your projects to the subversion repository. Do not forget to verify your submission on the web.
