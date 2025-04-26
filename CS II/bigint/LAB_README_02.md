# CS2 Lab - Testing I

# Lab - Testing I

---

## Objectives

- Learn how to create and use include guards
- Appropriate use of namespaces
- Discuss testing concepts and building tests

---

## Discussion

We will talk about:

- [Include guards](https://data-structures.cs.kent.edu/labs/Info/include_guard.html)
- [Using namespaces, `using` declarations](https://data-structures.cs.kent.edu/labs/Info/namespaces.html)
- Testing concepts
- Building test cases and Makefile

What test cases should there be for `Bigint`'s addition function?

### Building Test Cases

Refresher from lecture ([lecture slides](https://data-structures.cs.kent.edu/labs/Info/Software_Testing_for_CS_II.pdf) for reference)

There are three steps in a test:

1.  Set up the "fixture", the system to be tested
2.  Perform the test
3.  Verify the resultes, make sure there are no unwanted side effects

### Example

```
{
    // Setup fixture
    Bigint left(9);
    Bigint right(5);
    Bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left   ==  9);
    assert(right  ==  5);
    assert(result == 14);
}
```

---

## Setup

### Update _shared_

Update your shared/ folder in svn.

It is assumed that your provided material working copy is named _shared_ and that it is in your home directory. If not, adjust accordingly.

```

  cd           # Go to your home directory
  cd shared    # Go into your shared working copy
  svn update
```

You will get messages about files being added and updated.

---

## Subversion Quiz

As a part of your lab assignment, you must complete a quiz in Canvas. This quiz will cover what you learned in the previous lab about Subversion.

You have the entire lab to complete the quiz. You may not complete this quiz outside of your lab.

---

## Assignment

- Create tests for the following operators in Bigint. Remember we build tests cases first, then implement the code.

- `+` - addition
- `*` - multiplication

- Tests need to use `assert` and the `==` operator
- Tests must cover all situations for add and multiply.
- Take advantage of techniques discussed in lecture and lab to construct the test cases.
- What are the inputs? What are the outputs? What are the equivalence classes? What are the boundary values?
- Remember that the best test case has a high potential for uncovering a failure.

---

## Requirements

The following must be true when you are done, **NAMES MUST MATCH EXACTLY**:

- In your _cs23001_ directory you have created a directory named _bigint_.
- In the directory _bigint_ you have the following files:

- `test_add.cpp`
- `test_multiply.cpp`
- The test files do NOT need to run or compile at this time as you do not have the add or multiple implemented. They should have a good comprehensive set of tests, this should help you implement the methods.

- There are **NO** executables in the repository.
- Your programs compile, run, and perform as specified using the Makefile.
- Your programs follow the [General Program Requirements](https://data-structures.cs.kent.edu/labs/Info/general_prog_req.html).

### Verify Commit

Use the browser one more time to verify that your work has been committed.

[http://svn.cs.kent.edu/courses/cs23001/svn/USERNAME](http://svn.cs.kent.edu/courses/cs23001/svn/USERNAME)

You can click on the above link then replace "USERNAME" in the browser's location box with your information.

### Final Note

Upon completion of this assignment it will be assumed you are comfortable with the skills used in this assignment.

Do not hesitate to ask your instructor if you have questions or problems.

---

URL: https://data-structures.cs.kent.edu/labs/Lab3  
Last update: 01/27/2025 21:09:42 EST

---
