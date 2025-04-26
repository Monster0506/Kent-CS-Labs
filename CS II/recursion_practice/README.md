# CS2 Lab - Recursion

# Lab - Recursion

---

## Objectives

- Discuss recursion, tail recursion, and the call stack

---

## Discussion

- Recursion, the call stack, ease of finding solutions to recursively definable problems
- Say we have two functions:

- `DrawLine`
- `DrawSquare`

- If we called them such that `DrawSquare` is called first, followed by `DrawLine`, we get a call stack that looks like:

![Image 1](http://upload.wikimedia.org/wikipedia/commons/e/e7/Call_stack_layout.png)\* Let's define some terms:

- Stack Frame - Data structure that contains information about a function that has been called and has not yet terminated.
- Stack Pointer - Points to the top of the stack and the function that is currently in-use.
- Return Address - Where to go once function has terminated; the point where the function was called from.
- Locals - simply refers to cariables declared within the function
- Parameters - simply the variables passed to the function when it was called

- Implementation details of the stack are beyond this class' scope, but what we see from here suffices for talking about recursion. We'll talk about two types of recursion:

- Regular Recursion (just Recursion) - Which grows the stack linearly until some base-case is satisfied
- Tail Recursion - Which does not grow the stack

- **Recursion**: Regular recursion is when every recursive call is made before any calculations are performed. This menas that every time the function is called, the call stack will gain a new copy of the function.

```
int triangle_number(int n) {
    if(n == 0) { return 0; }
    else {
        int value = triangle_number(n - 1); // Recursive call is made first
        return n + value; // Then, after all recursive calls, the calculations are done
    }
}
```

- **Tail Recursion**: Tail recursion differs from regular recursion in that a calculation is done before the recursive call is made, and the running total is passed through the recursive call. Because the calculations are all done before the recursive call is made, you don't need the current stack frame, and the compiler can optimize the code so that the call stack won't grow.

```
int triangle_number(int n, int running_total) {
    if(n == 0) { return running_total; }
    else {
        running_total += n; // The calculation is performed first
        return triangle_number(n - 1, running_total); // Then the recursive call
    }
}
```

---

## Setup

We need to:

1.  Create a directory called _recursion_practice_ in your _cs23001_ folder
2.  Create `fibonacci.cpp`

---

## Assignment

Fibonacci sequences are a sequence of integers where at each position, `n`, the value at `n` is the the two previous values at `n - 1` and `n - 2`. We will use 0 and 1 as the first two digits in this assignment. The sequence would be: `0 1 1 2 3 5 8 13 21 34 etc...`. You are to implement the Fibonacci sequence:

- Recursively and Tail Recursively
- So that every number in the sequence is printed

---

## Requirements

The following should be true when you are done, **NAMES MUST MATCH EXACTLY**:

- In your _cs23001_ directory you have created a directory named _recursion_practice_.
- In the directory _recursion_practice_ you have the following files:

- `fibonacci.cpp`

- There are **NO** executables in the repository.
- Your program compiles, runs, and performs as specified.
- Your program follows the [General Program Requirements](https://data-structures.cs.kent.edu/labs/Info/general_prog_req.html).

---

URL: https://data-structures.cs.kent.edu/labs/Lab9  
Last update: 10/15/2024 14:53:47 EST

---
