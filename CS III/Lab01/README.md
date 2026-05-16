# Procedural Diff

## Lab Assignment

Implement the lab using procedural programming techniques only. That is, you are not allowed to define classes or objects.

**Diff.** Implement a program that compares two text files character-by-character. The program should output the line numbers that contain different characters and the place where the two lines start to differ. The difference is denoted by ^ (caret) character. If both files are identical, the program should output nothing.

File lengths may differ. If one file is shorter than the other, the shorter file is assumed to have empty lines, i.e. the extra lines of the longer file are considered different from the empty lines of the shorter file.

 The file names should be passed as arguments on the command line. Assume the files exist. Assume the file names are the same length. If your program is not invoked with two arguments, it should print an error message and quit. The program operation should look like this: 	prompt% ./diff file1.txt file2.txt

	file1.txt: 20: Hello
	file2.txt: 20: Hallo
                        ^
	file1.txt: 25: World????
	file2.txt: 25: World!
                            ^
 where 20 and 25 are line numbers. 
You are allowed to use getline() and string comparison functions in the implementation of this project.

You may use [these files](http://antares.cs.kent.edu/~mikhail/classes/cs3/Labs/Lab1/testfiles.html) to test your program and to check the expected output.

**Milestone**. Code that inputs two lines from two different files and determines whether they are the same.

**Hint**. The command line arguments are input as C-style strings arguments to main(). [See this program](http://antares.cs.kent.edu/~mikhail/classes/cs3/Labs/Lab1/commandLine.cpp) for an example of handling them.

To configure command-line arguments for an MS Visual Studio project, right-click Solution Explorer, select "properties" from the drop-down menu, go to Configuration Properties Debugging and set "Command Arguments" in the properties list.

To create a string of spaces of a particular length use this form of initialization: string spaceString(length, ' '); or 

 use assign operator: spaceString.assign(length, ' ');
