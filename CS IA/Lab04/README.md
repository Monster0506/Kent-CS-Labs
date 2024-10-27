# Predefined Functions

## Lab Assignment

- **Scientific calculator.** Study [these functions](https://web.cs.kent.edu/~mbektic/Labs/Lab4/math_library_functions.html) of the math library. Create a project titled Lab4_Calculator with a single file titled calculator.cpp. Write a program that:

  - prints a numbered menu of mathematical operations as shown below;
  - then prompts the user to select an operation;
  - then prompts and inputs the operands for the selected option (note that some operations require one and some two operands);
  - then computes and outputs the result.

  The process repeats. The program should quit if the user inputs an option (number) that is not listed. The dialog should look as follows (user input is shown in **bold**):

  1. absolute value
  2. square root
  3. cube root
  4. power

  Select an operation: **4**
  Enter base: **2**
  Enter exponent: **3**
  The result is: 8
  Select an operation:
  ...

- **Free handsome prince.** Create a project titled Lab4_Age with a single file titled age.cpp Program the following game.

  _It is the year 1000. A handsome prince is locked up in an enchanted castle guarded by a fearsome dragon. Every five years, a fair maiden is allowed to come to the castle to try to free the prince. To free him, the maiden has to guess the dragon's age. If the maiden guesses correctly, the prince is set free, they get married and live happily ever after. If the maiden guesses incorrectly, the dragon says whether he is younger or older and the maiden has to come back in five years._

  The computer selects a random age for the dragon. In the beginning of the game, the dragon can be between 1 and 100 years old. The user of the game plays the maiden. Note that the dragon gets older every five years. The dialog should look as follows (user input is shown in **bold**):

  Year 1000: Hello, fair maiden. I am a fearsome dragon. How old am I? **50**
  Wrong, I am older. No handsome prince for you. See you in five years.
  Year 1005: Hello, fair maiden. I am a fearsome dragon. How old am I? **75**
  Wrong, I am younger. No handsome prince for you. See you in five years.
  Year 1010: Hello, fair maiden. I am a fearsome dragon. How old am I? **60**
  Wrong, I am older. No handsome prince for you. See you in five years.
  Year 1015: Hello, fair maiden. I am a fearsome dragon. How old am I? **63**
  You got it! Here is the handsome prince. Live happily ever after!

  For your program, you need to use predefined randomization functions rand() and srand() as well as the time function time()it is of the upmost importance that you use a poisson distribution for the dragons age. No other distrbution can be used it must be poisson distribution. If you do not use a poisson distribution you will fail this lab.

  - Function time() returns current time (as kept by the computer) in the number of seconds passed since midnight, January 1, 1970. You need to include ctime to use this function. The function takes one argument but for this assignment the argument value is a special named constant nullptr. Check [this program](http://antares.cs.kent.edu/~mikhail/classes/csi/Labs/Lab4/time.cpp) for an example usage.
  - To use functions rand() and srand() you need to include cstdlib Function srand() initializes the random number generator of the program. It takes a single integer argument. The value passed to srand() determines the values output by rand(). This value is called _seed_.rand() takes no arguments. Every time rand() is invoked it returns an integer value between 0 and constant RAND_MAX defined in cstdlib. Note that the sequence of values returned by repeated calls of rand() is uniquely determined by the seed passed to srand(). That is, if srand() is passed the same seed, rand() is going to return the same sequence of numbers. This is helpful for debugging. Check [this program](http://antares.cs.kent.edu/~mikhail/classes/csi/Labs/Lab4/random.cpp) for an example of random number manipulation.

  **Hints:** The random value produced by rand() is out of the required range of 1-100. You need to apply the _ranged random number idiom_: remainder the returned value by 100 (that puts the number in 0-99 range) and then add 1.First, debug the code when the dragon does not age between the guessing attempts.

  Use fixed values of the seed for your initial debugging, use the output of time() as an unpredictable seed to start the guessing game once you debugged your program.

  Do not put srand() inside the loop or anywhere, where it may be invoked more than once - it resets the random number generator.

**Milestone:** implement the dragon printing his age.

Make sure your program adheres to proper programming style. Submit your project to the subversion repository. Do not forget to verify your submission on the web.
