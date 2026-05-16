# Roster with Class Schedule

## Lab Assignment

The project contains two parts.

1.   Recode the [roster](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/STLContainersSequential/Roster/roster.cpp) example we studied in class such that it lists the classes each student is enrolled in. Example roster files are [here](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/STLContainersSequential/Roster/). Here is an example printout: all students, dropouts removed and sorted
first name last name: courses enrolled
Andrew Turner:cs3 
Betty Torres:cs1 
Brian Sanchez:cs1 cs4 
...
[Here](http://antares.cs.kent.edu/~mikhail/classes/cs3/Labs/Lab4/classScheduleTestOutput.txt) is the output for the above example roster files. 
The container of the master student roster should be modified as follows: the vector (or other sequential container) should contain student entries. Each entry is a linked list (or other sequential container) where the first entry is the first (or last) name, followed by entries of the courses the student is enrolled in. You are not allowed to use associative containers. The advisable structures are as follows: vector<list<string>> studentEntries, vector<vector<string>> studentEntries, or list<list<string>> studentEntries

The printed out list may be tab-separated. You may assume that the text file structure is: one name per line; the line contains a first name followed by last name separated by white space. Each student has exactly two names: first and last (no middle names). The course name is the file name without the extension.

2.   Repeat the assignment for the object-oriented version of the code [shown here](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/STLContainersSequential/Roster/rosterObject.cpp). You need to modify the class Student to include a list of classes the student is enrolled in. 
In this assignment, implement a move constructor and demonsrate its operation in your code. Refer to [this example](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/STLContainersSequential/Vectors/moveIntArray.cpp) for move semantics implementation.

**Milestone:** Complete the first part of the project.
