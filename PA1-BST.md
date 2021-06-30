# PA1: BST in C++

## Due: by 11:59pm on Wednesday 7/7/2021.

## Table of Contents
- [Overview](#Overview)
- [Academic Integrity and Honest Implementations](#Academic-Integrity-and-Honest-Implementations)
- [Retrieving Starter Code](#Retrieving-Starter-Code)
- [Part 1: Binary Search Tree in C++](#Part-1-Binary-Search-Tree-in-C++)
  - [1. Examine and understand the code](#1-Examine-and-understand-the-code)
  - [2. Implement methods in BSTNode.hpp, BSTIterator.hpp, and BST.hpp](#2-Implement-methods-in-BSTNodehpp-BSTIteratorhpp-and-BSThpp)
  - [3. Check for memory leaks](#3-Check-for-memory-leaks)
- [Testing your code and getting help](#Testing-your-code-and-getting-help)
- [Getting Help](#Getting-Help)
- [Submission Instructions](#Submission-Instructions)
  - [Submitting Your PA](#Submitting-Your-PA)
  - [Grading](#Grading)

## Overview
* In this project, you will be asked to complete two major tasks. The first is to implement some number of BST methods. This part is essentially a warmup on C++ programming in the STL. The second part is to complete a worksheet quiz on gradescope. **Your first step is to _read these instructions carefully_** before you start writing code or post questions on edstem.
* This is a solo Programming project. You may ask Professors/TAs/Tutors for some guidance and help, but you can not copy code from anywhere including online sources such as Github. You may also discuss the assignment conceptually with your classmates, including bugs that you ran into and how you fixed them. However, do not look at or copy code, as this constitutes an Academic Integrity Violation. And you may not use other libraries’ implementations in your solutions.
* For this assignment and the remainder of the course, you are expected to use Git to keep track of your code and Github to store your code. Make a **private** repository (free on Github now) on Github, commit and push your code regularly as you go through the assignment.

**_Start early, and submit early and often!_**


## Academic Integrity and Honest Implementations
We will hand inspect all submissions and will use automated tools to look for plagiarism or deception. **Attempting to solve a problem by other than your own means will be treated as an Academic Integrity Violation.** This includes all the issues discussed in the Academic Integrity Agreement, but in addition, it covers deceptive implementations. For example, if you use a library (create a library object and just reroute calls through that library object) rather than writing your own code, that’s seriously not okay and will be treated as dishonest work.


## Retrieving Starter Code

## Part 1: Binary Search Tree in C++
In this part of the assignment, you will implement the fundamental BST operations using concepts from the C++ Standard Template Library, which includes writing an iterator for it. **Your BST does not need to handle duplicates.** You will then use your BST implementation in a speed comparison. You may find the stepik https://stepik.org/lesson/28727/step/1?unit=9785 (Section 3.3) useful for this PA.

### 1. Examine and understand the code
Your first task is to understand the code. Do not attempt to start writing code until you have a firm grasp of what the provided code does and what you are supposed to do with it. **Nearly all the required functionality is specified in the code and the comments, so you'll need to read everything carefully.** Make sure you can understand the provided test file `test_BST.cpp`, which partially tests some aspects of the BST class. Then you should add your own tests before you start implementing any code of your own, although we won’t be grading your testers.

### 2. Implement methods in BSTNode.hpp, BSTIterator.hpp, and BST.hpp

In **BSTNode.hpp**:
* **constructor**: `BSTNode(const Data & d)`
* **successor method** (this method is used in the BSTIterator's ++ operators to advance the iterator): `BSTNode<Data>* successor()`

In **BSTIterator.hpp**:
* **==method**:
```C++
bool operator==(BSTIterator<Data> const& other) const 
```
* **!= method**:
```C++
bool operator!=(BSTIterator<Data> const& other) const
```

In **BST.hpp**:
* **insert method**: `virtual bool insert (const Data& item)`
* **find method**: `virtual iterator find (const Data& item) const`
* **size method**: `unsigned int size() const`
* **height method**: `unsigned int height() const`
* **empty method**: `bool empty() const`
* **inorder method** (this method might be useful for debugging. Note our starter code has a inorder method that doesn't take a parameter. That method should call this method here because this prototype allows recursion.):
```C++
void inorder(BSTNode<Data>* n) const
```
* **first method**: `static BSTNode<Data> * first(BSTNode<Data> * root)`
* **deleteAll method**: `static void deleteAll (BSTNode<Data>* n)`
* **destructor**: `virtual ~BST()`


Implementation notes for BST:

1. When you implement these functions, any comparisons you make between two elements **must be done using the < operator**. The reason for this is that some data types in this project do not have the other operators (>, <=, >=, etc.) implemented, so for safety reasons, it's best to only use < to compare. Remember: given an element, you need to check if it's less than, greater than, or equal to elements currently in the BST. How can you do that with just the < operator?
2. Try to analyze different cases of successor() by examining the successor of all the nodes in a BST that you draw.
3. The first node is a BST is the one with the lowest value. A node's successor is the node with the next highest value. This means that iterating from the first node to each successor should list all nodes in ascending sorted order.

### 3. Check for memory leaks

The Makefile is provided for your convenience. Running make in the directory will compile your code and create the executable files. You should read and understand it as you will be required to submit your own Makefile in later assignments (but not this one). Your code should compile with the given Makefile as this is how we will compile and run your submission when grading. 

To check memory leaks, run valgrind on the BST tester:
```
> valgrind ./test_bst 
```

(there are lots of options you can use, but this is enough for now) 

* Notice under LEAK SUMMARY: If it reports that some memory was "definitely lost" then it means you have a memory leak. Check your deleteAll method and see if all the memories allocated are destructed or not!
* For details of what all the LEAK SUMMARY lines mean, see: http://valgrind.org/docs/manual/faq.html#faq.deflost

We have provided a more detailed guideline of testing in the second last part, make sure you read that carefully to guide your testing.

Note that the provided BST tester might not test your BST comprehensively, so you need to read the tester, understand what it does and come up with your own test cases.

## Part 2: worksheet for PA1

Complete the worksheet on gradescope with the open book open note policy. But you are not allowed to discuss any problem with any other student or tutors. Treat it like an open book, open notes exam. The deadline for the worksheet is the same as the coding component of the PA.

## Testing your code and getting help

**You will want to be sure to test your code at every step.** As a suggestion, you should write your own method which prints out all the details of the tree - that includes node contents along with left, right, and parent pointers. The time spent writing this code will more than offset the time you will save in debugging.

In C++, using the cout keyword is used to output values to stdout, but using cerr instead outputs to stderr. These can be convenient for easily filtering out program output in the terminal. Examples of how both of these are used can be found throughout the starter code. For added convenience, we also overrode the << operator for the BSTNode class so that outputting a BSTNode object will show you not only the node’s data but also its memory address and the memory address of its children and parent.

As a second suggestion, we recommend using debug print statements. These are statements which, if a #define flag is turned on, will print what the method is doing and possibly the state of the tree before and after. If the #define flag is turned off, all comments go away. It’s really helpful to get that debugging output from every method when you get stuck (and is significantly better than commenting in/out print statements). There are lots of ways to do this, but a nice suggestion from stackoverflow is:

```C++
#define DEBUG 1
#if DEBUG
#define D(x) x
#else
#define D(x)
#endif
```
You can then do debug print statements like this: `D( cout << ….;)`. But feel free to do what works best for you.

Most importantly, we encourage you to write your own BST Tester (feel free to use and extend test_BST.cpp and test_KDT.cpp as an example) which tests method by method as you add them to the code base. Be sure to test every method, no matter how simple. You don’t want to spend two hours debugging your insert method only to realize you messed up an equality test (trust us, we’ve done it…). (The test_*.cpp files we’ve provided for you stop execution at the first failure, so if you’re extending those files, add your tests above the ones already there.)

Lastly, our grading scripts use various methods to ensure your code is as efficient as it should be. Additionally, make sure that your program has no memory leaks, as this will also lose points. **Be sure to remove any debugging output from your BST before submitting** as I/O is expensive and could make an efficient method seem inefficient. **Also we compare your code's output with our reference solution's outputs.** If you have redundant output, your code will lose points!

## Getting Help

Tutors in the labs are there to help you debug. TA and Professor OH are dedicated to homework and/or PA conceptual questions, but they will not help with debugging (to ensure fairness and also so students have a clear space to ask conceptual questions). Questions about the intent of starter code can be posted on edstem. Please do not post your code to edstem either publicly or privately - debugging support comes from the tutors in the labs.

**_Format of your debugging help requests_**

At various times in the labs, the queue to get help can become rather long (all the more reason to start early). To ensure everyone can get help, we have a 5 minute debugging rule for tutors in that they are not supposed to spend more than 5 minutes with you before moving onto a new group. Please respect them and this rule by not begging them to stay longer as you’re essentially asking them to NOT help the next group in exchange for helping you more.

**_5 minutes?!_**

Yes, 5 minutes. The job of tutors is to help you figure out the next step in the debugging process, not to debug for you. So this means, if you hit a segfault and wait for help from a tutor, the tutor is going to say “run your code in gdb, then run bt to get a backtrace.” Then the tutor will leave as they have gotten you to the next step.

This means you should use your time with tutors effectively. Before asking for help, you will want to already have tried running your code in gdb (or valgrind, depending on the error). You should know roughly which line is causing the error and/or have a clear idea of the symptoms. When the tutor comes over, you should be able to say:

**What you are trying to do.** For example, “I’m working on Part 1 and am trying to get the insert method in the BST to work correctly.”

**What’s the error.** For example, “the code compiles correctly, but when I insert a child in my right subtree, it seems to lose the child that was there before.”

**What you’ve done already.**  For example, “I added the method which prints the whole tree (pointers and all) and you can see here _point to screen of output before and after insert_ that insert to the right subtree of the root just removes what was on the right subtree previously.  But looking at my code for that method, it seems like it should traverse past that old child before doing the insert. What do you suggest I try next?”

**Acknowledgements**

Special Thanks to Niema Moshiri, Christine Alvarado, and Paul Kube for creating the base on which this assignment is built.

## Submission Instructions

### Submitting Your PA

You can drag and drop your files or submit your code using Gradescope through Github submission option. You should have gotten enrolled in Gradescope by now (if not, please add your name to the appropriate edstem post). You should also be able to make **private** repositories on Github.

Instructions to submit your code on GradeScope:

1. **Be sure to test your code on ieng6.** We will be grading your code on the same environment as ieng6 and there may be issues with compilers/etc if you only tested your code on your personal machine.

2. Be sure to push the final version of your code to your private Github repository. That will be the code you will submit.

3. Go to gradescope and find PA1 submission. You will be asked to authorize your github account. After authorizing your account, choose the repo you pushed your PA1 code to and the correct branch.

4. You can submit as many times as you like before the deadline: only your last submission will be counted.

When you have completed all of the requirements for the final submission (All the parts). You should go to gradescope and find PA1 submission. **Only the files BST.hpp, BSTNode.hpp, and BSTIterator.hpp are submitted. Your code should not be in any other files than these.** This includes the fact that we do not pull your Makefile, so your code needs to compile using the given Makefile. You can always test this by adding just these files to a fresh set of the starter code and ensuring your code still works.

### Grading


* **Part 1 BST (70 points):** based on your implementation of BSTNode.hpp, BST.hpp, and BSTIterator.hpp, these are the files required for final submission

* **Part 2 Worksheet (20 points):** This is graded on gradescope separately from your code.

* **Memory leaks (10 points):** these points are earned for programs that do not have any memory leaks, so be sure to check your program with valgrind.

**_Code which does not compile will not be graded._**

Grading is holistic, and will be mostly black-box tested. This means that we mostly will not test your individual methods, but test your program as a whole. **It is very important that your output matches the output format mentioned in write up or any provided reference executables.**
