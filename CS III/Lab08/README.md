# Abstract Car Dealership, Bridge Painted Square

## Lab Assignment

 The project is due in one week: by the midnight on the day of the next lab. Make sure to include your name in comments of the source files. 
1.   **Abstract Car Dealership.** Consider the code for [Abstract Car Factory](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/AbstractFactory/CarFactory) studied in class. Modify the code as follows: The car buyers may now request a particular model as well as the make of a car (randomly selected). The dealer lot may hold up to 8 cars on his car lot. Initially, the lot contains 8 random cars. The buyer tries cars until he finds the one he likes (Ford or Toyota of particular model). The buyer then buys this car. If the buyer does not find the car he likes, he goes away (the function terminates). The dealer requests another car from a random factory to replace the one purchased. 

Specifically, create new methods of CarLot class called nextCar() and lotSize() Modify the car buyer function as follows. The buyer takes a new car for a drive with nextCar(). The buyer makes lotSize() attempts to find the car he likes.

2.   **Bridge Painted Square.** Modify the [Bridge Figures](http://antares.cs.kent.edu/~mikhail/classes/cs3/Examples/Bridge/bridgeFigures.cpp) example studied in class as follows: 
Make it so that the border and the inside of the figure can be painted with two different characters. Specifically, base class Fill should contain two characters: one for border paint, one for internal paint. The constructor for this class should now accept two characters to be assigned to the two member variables. The derived class Hollow should initialize the border paint to a character, and the internal paint character to a space. The derived class Filled should initialize both paints to the same character.

Create two more derived paint classes FullyFilled and RandomFilled. Class FullyFilled inherits from Filled but initializes both paint characters to two different values. For class RandomFilled, each time the getBorder() and getInternal() is invoked, it randomly returns one of the two characters. Demonstrate the operation of all four paint classes by drawing four differently painted squares.

**Milestone:** Abstract Car Dealership assignment.