# Objects with Dynamically Allocated Members

1. **List with Classes, Testing.**Create a project titled Lab11_ListTest. Implement the List of doubles described in the previous lab as a class List. You should use [this class definition](https://web.cs.kent.edu/~mbektic/Labs/Lab11/list.hpp). The class attributes are a pointer to the dynamically allocated array list\_ and the array size size\_ This class contains two groups of methods:

    - Member functions output(), check() addNumber() and removeNumber() have exactly the same functionality as described in the previous lab.
    - copy constructor, overloaded assignment and destructor ensure correct handling of the objects with dynamically allocated members.

    Your code should work with [this test program](https://web.cs.kent.edu/~mbektic/Labs/Lab11/test.cpp). It is designed to test your implementation of List class.

2. **Variable Size Array with Classes, Implementation.** Create a project titled Lab11_ListClasses. Using the class implemented in the first part of this lab, implement the functionality of the second part of the previous lab. That is, write a program that asks the user to input numbers to add to and remove from the array and then prints its contents. If the duplicate is entered, the program should state duplicate!

**Milestone:** implement addNumber(), removeNumber(), and check() functions for the first part of the assignment.

Make sure your programs adhere to proper programming style. Submit your projects to the subversion repository. Do not forget to verify your submission on the web.
