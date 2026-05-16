# Singleton Logger, Templated Dice

## Lab Assignment

 The project is due in one week: by the midnight on the day of the next lab. Make sure to include your name in comments of the source files. 
1.   **Singleton Logger.** Write code for a program that implements logging into a file using Singleton design pattern. Specifically, you need to implement a class Logger whose object has a public function report(const String&). Logger is first accessed opens a text file log.txt for appending. When report() is invoked, the argument string is appended to the file. When the program terminates, the log file stream is closed. You may implement either Classic or Meyers Singleton. See [this program](http://antares.cs.kent.edu/~mikhail/classes/cs3/Labs/append.cpp) for an example of opening a file for appending. Make sure to disallow singleton object copying (you may use either pre-C++11 or C++11 features to implement this). 
Demonstrate the operation of your object by invoking the report() in at least two separate functions.

2.   **Template Rock-Paper-Scissors.** Using the Templated Method Design Pattern, modify the [templated games](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/Inheritance/templateMethodGames.cpp) example as follows. Add a game of RockPaperScissors where two players try to win by selecting on of the tree objects: rock, paper and scissors. Rock beats scissors, paper beats rock, scissors beat paper. The first player is the computer. The computer randomly selects one of the three items. The second player is human. The program should aske the human player for the iteam and announce the winner. If the two items are the same, the program declares a draw and the game is replayed. 

 Here is an example dialogue: Human, (r)ock, (p)aper, or (s)cissors? **r**
Computer selected rock. It is a draw.

Human, (r)ock, (p)aper, or (s)cissors? **s**
Computer selected paper. You won!

In the template method example, you should not modify the base class template method, you should only write primitive operations for the new derived class RockPaperScissors

**Milestone:** Implement singleton logger (the first part of the assignment).
