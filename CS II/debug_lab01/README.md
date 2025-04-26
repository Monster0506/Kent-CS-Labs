# CS2 Lab - Debugging I

# Lab - Debugging I

---

## Objectives

- Go over debugging in C++
- Fix an example bug
- Go over the next part of Project 1

---

## Discussion

There are light and heavyweight methods for debugging in C++:

- Debugger (heavyweight)
- Output statements, assertions (lightweight)

- Standard Error (`stderr`, `std::cerr`)
- Standard Out (`stdout`, `std::cout`) along with `std::endl`
- Assertions

We prefer lightweight debugging methods when applicable. It is normally faster than using a debugger and requires no special, external tools (sometimes there is no debugger application). Using a debugger also has its use cases and can be very effective - for example, errors that occur after many iterations of a loop or deep recursive calls.

### Debugging Techniques

Debugging is the process of identifying and fixing errors in your code. These errors often lead to unexpected or wrong behavior during execution, and are not always obvious how to fix.

There are many different techniques for debugging - mainly to help identify the location of the error.

### Print Statements

Using print statements is one of the most effective ways to identify where an error is occuring. C++ errors messages can sometimes be very vague - for example, the infamous `Segmentation fault (core dumped)`. Seg faults can be caused by _many_ different issues, but in-general they relate to a memory problem. Unfortunately, the compiler does not (and typically can not) list where in the code the error ocurred - so, we have to find it ourselves.

**Locating the Error: Backtracking/Binary Search Debugging**: In your main function, start by placing print statements at the top and bottom. Recompile your code - the top print should run, but the bottom print shouldn't if you encounter an error. You know that the error must be happening somewhere in-between the two print statements. Add a 3rd print statement somewhere in-between and run your code. Does the 3rd statement print? If so, the error happens after - if not, the error happens before.

```
int main() {
    std::cout << "TOP OF MAIN" << std::endl;

    int arr[SIZE];
    foo(arr);

    std::cout << "1!" << std::endl;

    for(int i = 0; i < SIZE; ++i) { std::cout << arr[i]; }

    std::cout << "BOTTOM OF MAIN" << std::endl;
}
```

Output:

```
TOP OF MAIN
Segmentation fault (core dumped)
```

In the above example, `1!` never prints - thus, we know that the error is between the top print and the `1!` print - likely in the call to `foo`, as it is taking in an array.

You can repeat this process inside of the `foo` function to try to isolate exactly what line is causing the error. `foo` may call another function which is causing the error, so it is important to keep searching until you find the issue!

### Monitoring Local Variables and Program Flow

You have found where your error is happening, but you aren't quite sure why it is happening. Maybe you are trying to assign memory to an array, and it fails in the middle of your for loop. Maybe you have an infinite loop inside of a while loop, but you are pretty sure you coded the condition right. Or maybe you are trying to call `operator>` and your code is seg faulting for seemingly no reason.

Printing can help with all of these situations too. By locating the area where your error is ocurring, you can use print statements to print out the state of all variables nearby so you can trace exactly what is happening. This is especially useful when you have a loop, as you can have the looping variable (i.e., `i`) printed every time the loop refreshes.

You can also put print statements inside of if statements, so you can track the path that your code is taking. Putting a print in every if can help you immediately identify when a program is going somewhere at the wrong time.

```
bool operator<(const char*, const bigint& rhs) {
    return lhs < rhs;
}

int main() {
    std::cout << ("123" < bigint(999)) << std::endl;
}
```

Looking at the code above, it may not be obvious what is wrong. Running the code as is outputs:

```
Segmentation fault (core dumped)
```

Which isn't very clear. Using the steps from last section:

```
bool operator<(const char*, const bigint& rhs) {
    return lhs < rhs;
}

int main() {
    std::cout << "TOP" << std::endl;
    std::cout << ("123" < bigint(999)) << std::endl;
    std::cout << "BOTTOM" << std::endl;
}
```

Output:

```
TOP
Segmentation fault (core dumped)
```

This clearly shows that the error is happening somewhere in our < operator. But how could that be - it's only one line, and there's no memory management going on. Let's put a print statement in there just to check.

```
bool operator<(const char*, const bigint& rhs) {
    std::cout << "In operator<" << std::endl;
    return lhs < rhs;
}

int main() {
    std::cout << "TOP" << std::endl;
    std::cout << ("123" < bigint(999)) << std::endl;
    std::cout << "BOTTOM" << std::endl;
}
```

Now our output is:

```
In operator<
In operator<
In operator<
In operator<
In operator<
...
In operator<
In operator<
In operator<
In operator<
In operator<
Segmentation fault (core dumped)
```

This shows that the operator< is being ran over and over again forever, seemingly until our call stack runs out of space. This must be a circular definition - now, the bug can be identified and fixed.

### std::cout vs std::cerr

Instead of using `cout` for your print statements, `cerr` can be used instead. `cerr` is a separate stream of data from `cout`, and is intended to be used for printing error messages. `cerr` works independly from `cout`, which means that it can be routed to different places during output. Keeping your actual program output and error message separate can be very helpful for finding errors in programs with large outputs.

### Debug Flags

If you find yourself constantly commenting and uncommenting debug print statements, you may want to take advantage of a debug flag. By defining a `const bool DEBUG = false;` at the top of your code, you can wrap all of your prints in an if statement: `if (DEBUG) { /*...*/ }`. Then, when you want to turn the print statements on or off, simply switch the bool from being true or false.

### Rubber Duck Debugging

Another helpful way to try to identify and fix stubborn bugs is to simply talk about them! When you have an annoying bug that you just can't figure out, it can be helpful to simply talk about it with someone - a classmate, roommate - even an inanimate object! This process is called "Rubber Ducking" due to an anecdote in a textbook (_The Pragmatic Programmer_) where a developer would carry around a small rubber duck, and would explain his code, line by line, to the duck to solve problems. This sound crazy and weird, but this really helps! Being able to understand your code enough to explain it to someone else gives you an opportunity to think about everything from a different perspecitve, and can lead you to finding bugs. You can do this with anything - if you want a slightly interactive rubber duck, try [rubberduckdebugging.com](https://rubberduckdebugging.com/cyberduck/).

---

## Setup

We need to:

1.  Update the `shared` folder in your home directory
2.  Copy the directory named _debug_lab01_ from the _shared_ folder to your _cs23001_ folder. Remember the `cp` command?

---

## Assignment

The `bug1.cpp` file you have been given has one or more bugs in it. You may **NOT** use a third-party debugging tool.

1.  Run the program to see what's going on
2.  Find the bug(s) using the techniques we discussed in class earlier
3.  Fix the bug(s) and re-run the program to confirm that you've fixed them all.

---

## Requirements

The following should be true when you are done, **NAMES MUST MATCH EXACTLY**:

- In your _cs23001_ directory you have copied the _debug_lab01_ directory.
- In the directory _debug_lab01_ you have the following file:

- The fixed `bug1.cpp`

- There are **NO** executables in the repository.
- Your program compiles, runs, and performs as specified, with any bugs(s) fixed.
- Your program follows the [General Program Requirements](https://data-structures.cs.kent.edu/labs/Info/general_prog_req.html).

---

URL: https://data-structures.cs.kent.edu/labs/Lab5  
Last update: 09/19/2024 20:02:52 EST

---
