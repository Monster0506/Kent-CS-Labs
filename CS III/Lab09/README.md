# Adapter Moving Square, State Scheduler

## Lab Assignment

 Make sure to include your name in comments of the source files. 
*   **Adapter Moving Square.** Expand [Figures Adapter pattern](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/Adapter) example studied in class (you may use either class or object variant) as follows. Add the following functions to LegacyRectangle class: 
    *   void move(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) implements generic repositioning and resizing of the figure; 
    *   getTopLeftX(), getTopLeftY(), getBottomRightX(), getBottomRightY() return the respective corner coordinates. 

Using these functions, implement the following functions in the adapter class SquareAdapter

    *   int size() returns the current square size; 
    *   void resize(int newSize) changes the size of the figure by moving its bottom right corner. 

Demonstrate this functionality by coding main() as follows: ask the user for the size of a square, declare a square of the user-specified size, draw the square; then ask the user for a new size, resize the square to the new size and redraw it.

*   ![Image 1](http://antares.cs.kent.edu/~mikhail/classes/cs3/Labs/3stateModel.png)**State Transitions.** Using State Design Pattern, implement Process class that provides an interface to the three state process model of operating system scheduler implementation. The process may be in one of the states shown in the figure. The states should implement transitions as shown. A process should start in Ready state. 
Each process should have a unique identifier (**Hint:** maintain a static variable in class Process to keep track of the next available identifier, then increment the identifier once a new process is created.) The states should also implement a reporting function outputting what state the process is in. The process should be able to output:

process 1 is running
 If the transition is not in the appropriate state, for example if dispatch is invoked on a process that is in running state, no action should be taken (no state transition should occur). 

**Hint:** Use the state of Zork example that we studied in class a point of departure for your implementation.  Implement a process ready and blocked queue as follows. Use STL queue of processes. The first process in the queue is in running state, the rest are in ready. Randomly (with probability of 33% for each case), the running process may either exit, be suspended, or be blocked

    *   In case of exiting, the process is destroyed. 
    *   In case of suspension, the process becomes ready and moves to the tail of the ready queue. 
    *    In case of blocking, the process moves to the tail of blocked queue and becomes blocked. With a certain probability, the head process from the blocked queue moves to the ready queue and becomes ready again. 

Report on the state of processes after each transition. [See this file](http://antares.cs.kent.edu/~mikhail/classes/cs3/Labs/schedulerExampleOutput.txt) for an example output.

Demonstrate correct implementation of your ready queue and by admitting and scheduling 4 new processes.

**Milestone:** Implement Moving Square.