# Templated List

## Lab Assignment

Modify the [list template example](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/TemplateIntro/ListTemplate/) as follows. Create a new templated class Collection that contains this list as a dynamically allocated member, i.e, the list contains a pointer to the first element.

You are not allowed to use STL containers. You are not allowed to use double-linked list. That is, you should use single-liked list only as in the original code. The class has to implement the following methods:

*   add(): takes an item as the argument and adds it to the collection, does not check for duplicates. You may implement it so that add() appends it either in the front or in the back of the list. 
*   remove(): takes an item as the argument and removes all instances of this item from the collection. The removed nodes should be properly deallocated. 
*   last(): returns the last item in the collection. 
*   print(): prints all items in the collection. The printout does not have to be in order. 
If the number of elements is greater than 10, then this function should also print "large container".

*    bool equal(const Collection&, const Collection&) : compares two collections for equality. Implement as a friend function. You may implement it only as a specific template. You may not implement it as a general template. You may not inline friend function definition inside the class template definition. See [this](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/TemplateIntro) for examples. 
*   implement the big three functions needed for the proper object handling: copy constructor, destructor, and overloaded assignment. 

Make sure that your templated list operates correctly with the [following code](http://antares.cs.kent.edu/~mikhail/classes/cs3/Labs/Lab3/testCollection.cpp). You may use this [Makefile](http://antares.cs.kent.edu/~mikhail/classes/cs3/Labs/Lab3/Makefile) to assist in running and debugging your program. It is configured to use valgrind to help with debugging memory leaks.

Templated member functions should be implemented out-of-line (outside the class).

**Milestone**. Collection that successfully implements add().
