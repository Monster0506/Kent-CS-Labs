# Roster with Class Schedule, Associative; Set of Students

## Lab Assignment

1.   Recode the [roster](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/STLContainersSequential/Roster) example we studied in class such that it prints the list of classes each student is enrolled in. 

 Here is an example printout: all students, dropouts removed and sorted
first name last name: courses enrolled
Andrew Turner:cs3 
Betty Torres:cs1 
Brian Sanchez:cs1 cs4 
...
[Here](http://antares.cs.kent.edu/~mikhail/classes/cs3/Labs/Lab5/classScheduleTestOutput.txt) is the output for the above example roster files. 
The project should be done using associative containers and class Student to hold the name of the student. Specifically, you need to use a map keyed by the class Student while value could be a list of classes the student is enrolled in. The map should be the ordered map. That is, the data structure to be used in as follows: map<Student, list<string>>

2.    Recode the roster example so that it prints all the students currently enrolled in at least one course. That is, enrolled in a course and are not in dropout list. The name of each enrolled student has to be printed exactly once. You have to use this data structure: set<Student>. Refer to [this set example](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/STLContainersAssociative/set.cpp) for guidance. Here is an example printout: Currently Enrolled Students
Andrew Turner 
Betty Torres
Brian Sanchez
...

**Milestone:** For the first assignment, print a master list of students (without classes they are enrolled in).
