# Decorator Observer Chain of Responsibility Coffee Shack

## Lab Assignment

1.   A "Coffee Shack" serves coffee to its customers that is composed of the base coffee: large ($10), medium ($7) or small ($5) and added ingredients: sugar ($1), cream ($2) and honey ($3). The ingredients can be added in any order and multiple times. Here is an example dialog for the order (customer's input is in bold): 
    Welcome to Coffee Shack, can I get you [l]arge, [m]edium, or [s]mall coffee? **m**

 Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one? **s**

 Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one? **h**

 Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one? **h**

 Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one? **d**

 Can I get your name? **Alex**

Alex, your medium coffee with sugar, honey, honey is ready. It will be $14, please.

 Code the service of "Coffee Shack" program using Decorator Design Pattern. Use [this header file](http://antares.cs.kent.edu/~mikhail/classes/cs3/Labs/drink.hpp) to define your base class. 
2.   Implement class Barista that serves customers. Code it such that there are three different experience levels: JuniorBarista, SeniorBarista, Manager. JuniorBarista may only prepare drinks with no added ingredients. Senior Barista may handle all added ingredients except for honey. Manager may handle all ingredients. Implement your barista class using Chain of Responsibility design pattern. In your dialog with customers, make sure to print the experience level of the barista preparing the order. 

3.    Extend your program as follows. In "Coffee Shack", the barista takes the customers' order and then prepares their drinks. The barista may serve her customers concurrently. Once the drink is ready, the customers are notified. Specifically, after taking an order, the barista randomly either notifies all customers that of one the drinks is ready or starts taking a new order. The drinks are not necessarily prepared in the FIFO order. 
Code the service of "Coffee Shack" using Observer Design Pattern. Create Customer objects. Store them in vector or a more specialized container. Have customers register with a Barista object. The customers should be notified at once. Then, each customer should determine if it is her drink. Here is an example dialog:

     Welcome to Coffee Shack, can I get you [l]arge, [m]edium, or [s]mall coffee? **m**

 Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one? **s**

 Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one? **d**

 Can I get your name? **Alex**

 Please wait, Alex.

 Welcome to Coffee Shack, can I get you [l]arge, [m]edium, or [s]mall coffee? **l**

 Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one? **h**

 Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one? **d**

 Can I get your name? **Brenda**

 Please wait, Brenda.

 Alex, your medium coffee with sugar is ready. It is prepared by a SeniorBarista. It will be $8, please.

 This is Alex, I got my coffee, thank you! 

 Brenda, your large coffee with honey is ready. It is prepared by a Manager. It will be $10, please.

 This is Brenda, I got my coffee, thank you!

 Welcome to Coffee Shack, can I get you [l]arge, [m]edium, or [s]mall coffee? ... 

Demonstrate the operation of your program on three concurrently served customers.

**Hint:** To simplify debugging, long input, as well as output, may be redirected from a text file on the command line:

  prompt% ./coffeeShackProgram < inputFile.txt > outputFile.txt
  
**Milestone:** Implement the first part of the assignment (the basic "Coffee Shack").
