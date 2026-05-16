# Composite Visitor Genealogy, Checkpointed History

## Lab Assignment

 The project is due in one week: by the midnight on the day of the next lab. Make sure to include your name in comments of the source files. 
1.   **Genealogy.** Review the code of [genealogical tree](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/Composite/genealogy.cpp) that uses Composite and two variants of the Visitor Pattern. Modify the program to work as follows. It needs to update the first names of a person to add a middle name. That is, the middle name string is appended to the first name after a space. The middle name is selected as follows: man's middle name is the first name of his father, woman's middle name is the first name of her mother. For example, if the father of Richard Moore is Michael, then Richard's first name should be changed to Richard Michael. If a person does not have the respective parent, no middle name should be added. 

Note that for the formation of the child's middle name, only the first name of the parent is used, not the parent's middle name.

You should re-use the Composite pattern of the genealogical tree example but write another Visitor that updates people's names. You do not have to properly de-allocate the data structure after the program finishes.

Demonstrate the operation of your program by using the NamePrinter visitor to print the update names of all the people.

**Hint:** you need to add setFirstName() function to person class. You also need to modify the Composite class so that the first name is not constant

2.   **History.** Review the code of [Command](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/Command) and [Memento](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/Memento) design patterns that we studied in class. Also, review the Prototype Design pattern. Merge the functionality and design Command and Memento as follows. After printing the text stored in the document, the menu should give the user the following options: Enter option (i)nsert line (e)rase line (u)undo last command (c)heckpoint roll(b)ack
(h)history (r)edo command:
 The functionality of the first five options is as in the example code. The two new options operate as follows. The program keeps the command history only from the time of the last checkpoint. In case a new checkpoint is taken, the history is purged. 
    *   (h)istory option prints out a numbered list of commands that are retained in the history. You may have to add show() member function to Command class. Here is an example: 1. erase line 2
2. erase line 3
3. insert "Hello, World!" at line 1
    *   (r)edo command option asks for the command history number and applies it. The re-applied command is cloned with the Prototype Design Pattern. 

history listing command should not be retained in the list of commands. Neither should redo, only the original repeated command. For example, if the above history was listed, then second command is redone and then history listed again, then the history

    1. erase line 2
2. erase line 3
3. insert "Hello, World!" at line 1
4. erase line 3

**Note:** Retaining pre-checkpoint history and implementing the requested functionality without using the Memento Design Pattern or Prototype Design Pattern is not allowed.

**Milestone:** Implement the "middle name" part of the assignment.
