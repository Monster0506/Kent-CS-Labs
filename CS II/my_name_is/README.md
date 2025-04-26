# CS2 Lab - Getting Started

# Lab - Getting Started in CS II Lab

---

## Objectives

- Understand [lab policies](https://data-structures.cs.kent.edu/labs/Info/lab_policy.html)
- Understand [grading policies](https://data-structures.cs.kent.edu/labs/Info/general_prog_req.html)
- Understand [Discord policies](https://data-structures.cs.kent.edu/labs/Info/discord.html)
- Learn to access your KSU Linux account, basic Linux commands, and terminal based editing.
- Understand how to use subversion (SVN) for assignment submission

---

## Discussion and How To

- [Log into](https://data-structures.cs.kent.edu/labs/Info/access_linux_account.html) your Linux account with the PUTTY Client program (or any other SSH client).
- Using [Subversion](https://data-structures.cs.kent.edu/labs/Info/svn.pdf), check out a working copy of your svn folder [Working Copy Setup](https://data-structures.cs.kent.edu/labs/Info/working_copy_setup.html).
- Use a browser to view your Subversion repository directory.

  Type the following URL in the browser, but replace "USERNAME" with your Kent State username.

  [http://svn.cs.kent.edu/courses/cs23001/svn/USERNAME](http://svn.cs.kent.edu/courses/cs23001/svn/USERNAME)

  You can also click on the above link and then replace "USERNAME" in the browser's location box.

- These are the [CS II lab policies](https://data-structures.cs.kent.edu/labs/Info/lab_policy.html).
- These are tutorial videos on how to use the UNIX/Linux terminal (for future reference):

- [Linux Command Line Tutorial For Beginners 1](https://www.youtube.com/watch?v=YHFzr-akOas)
- [Linux Command Line Tutorial For Beginners 2](https://www.youtube.com/watch?v=dQ8JgDUS8DA)
- [Linux Command Line Tutorial For Beginners 3](https://www.youtube.com/watch?v=FTTr2bjI2UM)
- [Linux Command Line Tutorial For Beginners 4](https://www.youtube.com/watch?v=E01hskdRmUg)
- [Command Line vs GUI](https://www.youtube.com/watch?v=G0LsYZ7Kwh8)
- [Relative and Absolute Paths](https://youtu.be/MYdgugJT0TQ)
- [Move and Copy](https://youtu.be/eyV0gLFuCDQ)
- [Remove Files and Directories](https://youtu.be/2YLhxyh5_VE)

---

## Setup for the Assignment

The assignment is named _my_name_is_

It is assumed your **working copy** (check [Working Copy Setup](https://data-structures.cs.kent.edu/labs/Info/working_copy_setup.html)) is named `cs23001` and is in your home directory. If not, adjust as needed

You need to:

### Create the directory for this assignment inside the `cs23001`

Anything that follows the # is a comment (like `//` in C++). You don't need to type the comments.

```
  cd                         # Go to your home directory
  cd cs23001                 # Go into the working copy of your programs
  pwd                        # Print working directory, just to show where you're at
  ls                         # No my_name_is
  svn mkdir my_name_is       # USE THIS NAME EXACTLY
  ls                         # my_name_is now present
  svn commit -m "Directory for my_name_is program"
```

There should be no error messages. If there are error messages, try to fix them or ask your instructor to help.

You can verify the commit with your browser as we did in the discussion. Click the following link then replace "USERNAME" with your username in the browser's location bar

[http://svn.cs.kent.edu/courses/cs23001/svn/USERNAME](http://svn.cs.kent.edu/courses/cs23001/svn/USERNAME)

## Assignment

---

### Overview

There are 3 parts to this lab:

1.  View the repository directory with a browser.
2.  Log into your Linux account, create a file in the repository using Linux commands.
3.  Write a program that outputs your name.

### Viewing Your Repository Directory

Use the browser to view your repository directory.

Type the following URL in the browser, replace USERNAME with your username.

[http://svn.cs.kent.edu/courses/cs23001/svn/USERNAME](http://svn.cs.kent.edu/courses/cs23001/svn/USERNAME)

Or, you can click on the above link then replace USERNAME in the browser's location box with your username.

### Creating a File

Log in to `wasp.cs.kent.edu` or `hornet.cs.kent.edu` as explained in the discussion. Your username and password are the same as the those you use to view your repository directory with the browser.

Create a file in the repository. Use the following commands:

```
  cd                            # Go to your home directory
  cd cs23001                    # Change directory into your working copy
  ls                            # List files and directories, you should see my_name_is
  cd my_name_is                 # Change directory
  touch my_name_is.cpp          # Create the .cpp file for your program
  ls                            # You should see my_name_is.cpp
  w                             # Show who is logged on
  w > who.txt                   # Put the output of the who command into a file
  cat who.txt                   # Show the contents of the file
  svn add who.txt               # Put who.txt under version control
  svn commit -m "svn practice"  # Send the file to the repository
```

View the file in the repository with the browser.

### My Name Is Program

Write a program that outputs My name is followed by your name.

Name your program `file my_name_is.cpp`. You should have done this in the previous step.

Use whatever [development approach](https://data-structures.cs.kent.edu/labs/Info/editor-guide.html) you like.

Compile your program: `clang++ -Wall my_name_is.cpp`

Run your program: `./a.out`

Make sure the file your repository directory, in the subdirectory my_name_is. Compilation will be gone over in more detail in a later lab.

Commit your program. Remember to use the `svn add _filename_` and `svn commit -m "_message_"` commands.

View the file in the repository with the browser (click on reload if necessary).

There is no project assigned yet so there is nothing else to work on.

---

## Requirements

The following should be true when you are done, **NAMES MUST MATCH EXACTLY**:

- In your _cs23001_ directory you have created a directory named _my_name_is_.
- In the directory _my_name_is_ you have the following files:

- `my_name_is.cpp`
- `who.txt`

- The files and directory have been committed.
- The above files are the **ONLY** committed files in your _my_name_is_ repository directory.
- There are **NO, NONE, NADA** executables in the repository.
- Your program compiles, runs, and performs as specified.
- Your program follows the [General Program Requirements](https://data-structures.cs.kent.edu/labs/Info/general_prog_req.html).

### Verify Commit

Use the browser one more time to verify that your work has been committed.

[http://svn.cs.kent.edu/courses/cs23001/svn/USERNAME](http://svn.cs.kent.edu/courses/cs23001/svn/USERNAME)

You can click on the above link then replace "USERNAME" in the browser's location box with your information.

### Final Note

Upon completion of this assignment it will be assumed you are comfortable with the skills used in this assignment.

Do not hesitate to ask your instructor if you have questions or problems.

---

URL: https://data-structures.cs.kent.edu/labs/Lab1  
Last update: 01/15/2025 15:07:45 EST

---
