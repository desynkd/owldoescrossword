Crossword Solver in C - Desynkd

Task:
For this project, you will write a C program to solve a crossword puzzle. Your program should read, from 
standard input, a puzzle grid and a set of words and should print the solved puzzle to standard output.
 
Specification: 
A partially filled puzzle grid will be given in the input with stars, hashes and letters. Stars indicate 
blocked cells (cannot be filled). Hashes indicate vacant cells needed to be filled with letters. The inputs 
will also include the words to be used, one per line, in random order. If your program finds out that 
filling the crossword puzzle is impossible with the given words, you should print IMPOSSIBLE. 

Input: 
The grid is followed by an empty line and a list of words, one per line. To finish giving words, an empty 
line is provided. 

Output: 
The completed puzzle, the message “IMPOSSIBLE” or “INVALID INPUT”. 

Test cases: 
Here are some test cases. This is NOT the complete set of test cases used to evaluate your submission. 
Therefore, you are advised to formulate your test cases (in addition to what is given here) and test your 
program. 

Testcase 01: 

Input : 

**** 
#### 
**** 
*### 

FIRE 
CAT 

Expected Output: 

**** 
FIRE 
**** 
*CAT 