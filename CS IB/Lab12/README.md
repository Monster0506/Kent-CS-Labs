# Objects with Dynamically Allocated Members

# Vectors

1. **Vectors.** This lab is to be done using Unix. To familiarize yourself with Unix, [read this tutorial](https://web.cs.kent.edu/~mbektic/Labs/Unix/tutorial.html).To prove that you used Unix tools, as part of your project submission, you need to submit a typescript file with the record of at least one successful compilation of the fist project program below (the execution of the compiler on your source code file). Create a project titled Lab12_ListVectors. Implement the dynamically expanding and contracting list functionality described in previous labs using vectors. In the main() function, you may declare the vector to hold characters input. Lower and upper case are considered diffrent characters i.e. 'a' and 'A' are not the same char.

   Specifically, your program has to support this dialog:

```bash
    enter operation \[a/r/q\] and character: a C
    your characters: C
    enter operation \[a/r/q\] and character: a D
    your characters: C D
    enter operation \[a/r/q\] and character: a D
    duplicate!
    your characters: C D
    enter operation \[a/r/q\] and character: r D
    your characters: C
    enter operation \[a/r/q\] and character: r E
    not present!
    your characters: C
    enter operation \[a/r/q\] and character: a J
    your characters: C J
    enter operation \[a/r/q\] and character: a A
    your characters: C J A
    enter operation \[a/r/q\] and character: a a
    your characters: C J A a
    enter operation \[a/r/q\] and character: q
```

**Hint:** You may use insert with an iterators for character addition, or push_back. Refer to [this code](https://web.cs.kent.edu/~mbektic/Labs/Lab12/push_back.cpp) for example usage.
**Hint:** use iterators for character removal. Use find() algorithm to check if the character is present in the vector. Refer to [this code](https://web.cs.kent.edu/~mbektic/Labs/Lab12/iteratorAlgorithms.cpp) for example usage.

**Milestone:** Demonstrate program compilation in Unix and implement addition to the vector in the assignment.

Make sure your programs adhere to proper programming style. Submit your projects to the subversion repository. Do not forget to verify your submission on the web.
