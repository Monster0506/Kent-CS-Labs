# CS2 Lab - Object Creation and Destruction

# Lab - Object Creation and Destruction

---

## Objectives

- Discuss array bounds checking on the heap
- Talk about pointers, reference values, copy constructors, destructors, and assignment
- Memory error/leak detection using `valgrind`

---

## Discussion

We will look at some code examples - These code examples can be found in the shared folder, under `obj_creation_deletion`:

- Allocating arrays and bounds checking
- Pointers
- Calling a copy constructor
- Calling an overloaded assignment operator
- Calling a destructor

We will run `valgrind` to show memory errors.

### Using `valgrind`

To run `valgrind` do:

```
valgrind ./executable_file
```

Run `valgrind` on your test programs to make sure there are no memory problems or if something unusual is happening.

A `Makefile` can be configured to run `valgrind` on test programs.

### Pointers and Arrays

There is a close connection between arrays and pointers.

Note how in the last example the pointer variable is used like an array once it has memory allocated.

---

## Setup

We need to:

1.  Update the `shared` folder in your home directory
2.  Create a directory called _object_construction_ in your _cs23001_ folder
3.  Copy `obj_creation_deletion/array_bounds_check.cpp` from the `shared` directory into `object_construction`.
4.  Create `object_construction.cpp`, `object_construction.hpp`, and `object_test.cpp` in the `object_construction` folder.

- `object_construction.cpp` is for your implementation
- `object_construction.hpp` is for the class
- `object_test.cpp` is where your main function and tests should go.

---

## Assignment

The first part of this lab is to open `array_bounds_check.cpp` in an editor and read over the code. There are instructions on how to compile and run the code. There are some questions to answer about the code and the various runs.

The next part of the assignment is an excercise about constructors and assignment calls. Your job is to write a small program (a class, an implementation, and a main) that calls the copy constructor, default constructor, assignment, and destructor.

It should output a message every time one of these are called: `"Called {Function}"`. After you've done so, look at the examples in shared and answer a few questions about how objects are constructed and deleted.

---

## Requirements

The following should be true when you are done, **NAMES MUST MATCH EXACTLY**:

- In your _cs23001_ directory you have created a directory named _object_construction_ .
- In the directory _object_construction_ you have the following files:

- The `arrays_bound_check.cpp` file with answered questions
- `object_construction.cpp`, `object_construction.hpp`, and `object_test.cpp`

- There are **NO** executables in the repository.
- Your programs compile, run, and perform as specified.
- Your programs follow the [General Program Requirements](https://data-structures.cs.kent.edu/labs/Info/general_prog_req.html).

---

URL: https://data-structures.cs.kent.edu/labs/Lab6  
Last update: 09/24/2024 16:52:44 EST

---
