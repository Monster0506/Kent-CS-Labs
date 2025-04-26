# CS2 Lab - UNIX Development

# Lab - UNIX Development

---

## Objectives

- Learn necessary Linux commands
- Understand Linux file system
- Learn how to compile your program with clang++
- Learn how to use Makefiles to build programs

---

## Discussion

We will talk about:

- The [UNIX Filesystem](https://data-structures.cs.kent.edu/labs/Info/unix_files.html)
- [Compiling](https://data-structures.cs.kent.edu/labs/Info/compiling.html)
- [`make` command](https://data-structures.cs.kent.edu/labs/Info/make.html)
- `class Bigint`

---

## Setup

We need to:

1.  Checkout a directory that has provided files.
2.  Create the directory for the bigint project.

### Make a directory for bigint in your "Student" Working Copy

It is assumed your working copy is named cs23001 and is in your home directory. If not, adjust the commands as needed.

In the commands below the # and characters that follow are comments, like `//` in C++, and do not need to be typed.

Do the following in a terminal:

```
  cd                   # Go to your home directory
  cd cs23001           # Go into the working copy of your programs
  pwd                  # Print working directory, just to show where you're at
  ls -l                # No bigint
  svn mkdir bigint     # USE THIS NAME EXACTLY
  ls -l                # bigint now present
  svn commit -m "Directory for bigint program"
```

There should be no error messages. If there are error messages fix the problem, talk to your instructor if necessary.

You can verify the commit with the browser. Click the following link then replace "USERNAME" with your username in the browser's location bar.

[http://svn.cs.kent.edu/courses/cs23001/svn/USERNAME](http://svn.cs.kent.edu/courses/cs23001/svn/USERNAME)

---

## Assignment

Create the files necessary for the `Bigint` type, part 1.

Work on the bigint project part 1.

Look at the project 1 page for `Bigint` milestone 1 details.

### Using UNIX to Create the Files

If you have not done so, carry out the instructions in the Setup section to create the `bigint` project directory

If you have not checked out the `shared` directory from the last lab, make sure you do so now. Follow the instructions in [Working Copy Setup](https://data-structures.cs.kent.edu/labs/Info/working_copy_setup.html)

Do the following commands in a terminal window.

```
  cd                            # Go to home folder
  svn update  ~/shared          # Update your shared folder
  cd cs23001                    # Go to your cs23001/bigint directory
  cd bigint
  touch bigint.hpp              # Create an empty file named bigint.hpp
  touch bigint.cpp              # Create an empty file named bigint.cpp
  svn add bigint.hpp bigint.cpp # Add the files to version control
  svn commit -m "Empty start files for bigint project"
```

### Copy the Provided Files

Copy the files:

```
  cp ../../shared/project1/*  .   # The . denotes the current directory
  ls -l                           # You should see additional files
```

Add the files to your working copy and commit:

```
  svn add Makefile
  svn add test_default_ctor.cpp
  svn add test_int_ctor.cpp
  svn add test_c_str_ctor.cpp
  svn add test_equal.cpp
  svn commit -m "Provided files"
```

### Work On the `Bigint` class for Project 1 Milestone 1

Work on the class `Bigint`.

First add stubs and get your programs to compile.

Stubs are functions that have one line in the body that returns an arbitrary value so that function declarations and definitions are present.

Use VSCode, a command-line editor (`vi`, `emacs`), or another editor to edit the files.

Use the provided makefile to build and run your programs.

In a terminal window type `make tests` to build and run the programs.

When the programs successfully build, implement the required functions so that the tests pass.

Typing `make clean` will remove .o files and the executable.

### Final Note

If you have extra time experiment with other UNIX commands and an editor.

Do not hesitate to ask your instructor if you have questions or problems.

---

## Requirements

The following should be true when you are done, **NAMES MUST MATCH EXACTLY**:

- In your _cs23001_ directory you have created a directory named _bigint_.
- In the directory _bigint_ you have the following files:

- `bigint.hpp`
- `bigint.cpp`
- `Makefile`
- Four test programs

- The files and directory have been committed.
- There are **NO** executables in the repository.
- Your program compiles, runs, and performs as specified using the Makefile.
- Your program follows the [General Program Requirements](https://data-structures.cs.kent.edu/labs/Info/general_prog_req.html).

### Verify Commit

Use the browser one more time to verify that your work has been committed.

[http://svn.cs.kent.edu/courses/cs23001/svn/USERNAME](http://svn.cs.kent.edu/courses/cs23001/svn/USERNAME)

You can click on the above link then replace "USERNAME" in the browser's location box with your information.

### Final Note

Upon completion of this assignment it will be assumed you are comfortable with the skills used in this assignment.

Do not hesitate to ask your instructor if you have questions or problems.

---

URL: https://data-structures.cs.kent.edu/labs/Lab2  
Last update: 01/24/2025 14:51:22 EST

---
