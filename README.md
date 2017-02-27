#Maze Solver
##1. Problem Description
Assume that a robot mouse moves around in a maze. Some paths through the maze
lead to dead ends (see the picture below). The objective of the mouse is to find a route
through the maze from the given starting point to the goal. Due to existence of dead
ends, random movement may lead to infinite loops. Certain backtracking strategies
must be used for recording previous branch points and avoiding the dead ends that
have been discovered.
This assignment concerns the use of stacks for backtracking as a solution of maze.
You are required to write a computer program for a robot mouse that can find a route
from the starting point to the goal in finite steps. You may use any data structures to
represent a maze and mouse movement but you should use stacks for backtracking.
You may use any high-level programming language for the implementation but highly
recommended to use C++ or Java.

###1.1 Maze Representation
You may design your own data structures to represent a maze. The easiest (but not the
best) way to represent a maze is to record it in a two-dimensional array of integers
(see diagram below).
The walls are represented by 1s in the array, passageways by 0s (show in blank in the
picture). The starting point is denoted by an 8 and the goal is denoted by a 9. Assume
that the starting point is always in the first column and the destination is always in the
last column1. A file maze.h is provided which contains an example of maze
represented in such an array (copy-and-paste the array data for Java users). The
position at any given instant in the maze can be recorded by the row and column in
the two-dimensional array.

###1.2 Movement
If we represent a maze as a two-dimensional array, the current position of the mouse
can be recorded by the row and column in the array. The mouse can move one block
at each time to up, down, left or right if not meets the wall. If meet a dead end, the
mouse needs to backtrack. To avoid the dead ends that have been discovered, you
may need to use one or more stacks to record the paths that have been walked through
and possible future moves, depending on the data structures you use. For instance,
you may use one stack for recording the path (path stack) and one stack for recording
possible moves (move stack). Assume that the current position is (row, col) and the
previous position is (row, col-1) as shown in the following diagram.

The position (row, col-1) will be on the path stack for the current path. There are 4
theoretically possible moves at each time but the previous position (which sits on the
top of the path stack) should not be considered only if all other three directions are
blocked (a dead end), in which case a backtrack occurs (pop the position in the stack
as your next move). Any cell in the other directions that contains a 0 should be
considered as a possible move. For the example shown in the above picture, you
should put (row-1, col) and (row, col+1) into the move stack but not (row+1,col) or
(row, col-1). To record the block that has been identified as a dead end, you may
mark it with any value except 0, 8 and 9.
Your program should find the goal and display the path you find from the starting
point to the goal.

##2. Requirements

###2.1 Language
You may choose any object oriented programming language for your implementation
but recommend using either C++ or Java.

###2.2 Data Structures
You are required to use stacks for backtracking but no restrictions on other data
structures. You can use STL stack for your implementation.

###2.3 Screen Display
You can simply print the current value of the maze matrix to show the status of each
move. Graphical display is not recommended and will not add more marks to your
result. I will show you the outcome of my code during the lecture.

###2.4 Complexity analysis
If you pursue Distinction or higher grade, you are required to conduct complexity
analysis of the efficiency of your algorithm. Assume that the size of the maze is n*n,
estimate the complexity of your algorithm in big O-notation in terms of the size.
Detailed analysis is expected for HD level. Please print a hard copy of your document
and give it to me when you demonstrate your program.

###2.5 Marking criteria
Pass Level (50-64 marks):
  1. Complete a program that can find a feasible path from the starting point to the end
point (49 marks)
  2. Correctly use stacks for backtracks (15 marks)

Credit Level (65-74 marks):
  1. Complete the tasks for Pass level (64 marks)
  2. The algorithm is clear and reasonably efficient (5 marks)
  3. Use OO style and has a clean finishing (5 marks)
 
Distinction Level (75-84 marks):
  1. Complete the tasks for Credit level (74 marks)
  2. Demonstrate that your maze solver can also solve any m*n mazes where m and n
are arbitrary positive numbers (5 marks)
  3. Algorithm description and analysis (documentation) (5 marks)

High Distinction Level (up to 100%):
  1. Complete the tasks for Distinction level (84 marks)
  2. Choose a task from the following options:
    *Option 1: Generate any size of mazes in a m x n square (6 marks).
    *Option 2: Convert your code from C++ to Java or from Java to C++ (6 marks).
  3. Program is very well written and highly efficient using right data structures in
right places (5 marks).
  4. Document is very well written (5 marks)
 
Extra tasks for advanced students:
  1. Complete all tasks for High Distinction Level
  2. Convert your code into a General Game Player and run it on the GGP Base
platform.

Remarks:
  1. If you pursue credit or higher grade, your code must be in OO style with clear
finish.
  2. If you pursue distinction or higher grade, you must submit a document with
algorithm analysis, which consists of explications of your algorithm and
estimation of complexity of your algorithm.
  3. If you pursue high distinction grade, you have to choose either converting your
code to another general purpose language or writing a maze generation program
that can generate any size of maze (m*n) without loop paths (so called perfect
maze). Your maze solver should be able to solve any maze that you generate (I
will demonstrate my code during the lectures).

See a separate file for detailed marking criteria.
