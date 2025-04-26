# CS2 Lab - Profiling

# Lab - Profiling

## Objectives

- [STL](http://en.cppreference.com/w/)
- Profiling
- Go over the Project 4

---

## Discussion

- Profiling is an activity we undergo in order to reason about the speed of our programs

- How fast does it execute overall?
- Which functions take the most time to execute?
- Which functions are executed the most?

- Useful for when we need to focus on optimizing prohrams for speed
- For more, see [profiling](<https://en.wikipedia.org/wiki/Profiling_(computer_programming)>)

---

## Setup

We need to:

1.  Create a directory called _sort_report_ in your _cs23001_ folder
2.  Copy the `sort.cpp`, `sort_lib.cpp`, and `sort_lib.h` files from _shared/project4_ into your _sort_report_ folder

---

## Assignment

- Let's profile the sort program

1.  `clang++ -std=c++11 -pg sort.cpp sort_lib.cpp`
2.  `./a.out -sz 30000 -bs` -- will create the `gmon.out` file
3.  `gprof ./a.out > out.txt` -- will run the profiler and put the output in `out.txt`

- Use the profiler on the sort program and report on which functions take the longest. How long do they take? Why do you think they're slow?
- In `sort_report/explanation.txt`, tell us what function in the sort program took the longest and give a small explanation (a few sentences) as to why this function(s) are bottlenecks.

---

## Requirements

The following should be true when you are done, **NAMES MUST MATCH EXACTLY**:

- In your _cs23001_ directory you have created a directory named _sort_report_.
- In the directory _sort_report_ you have the following files:

- The copied `sort.cpp`, `sort_lib.cpp`, `sort_lib.h` files from _shared/project4_
- `out.txt`, containing the results of running the profiler
- `explanation.txt`, detailing what function took the longest and why

- There are **NO** executables in the repository.

---

URL: https://data-structures.cs.kent.edu/labs/Lab13  
Last update: 04/22/2025 20:10:16 EST

---
