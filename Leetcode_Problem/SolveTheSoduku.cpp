/*

Solve the Sudoku
Difficulty: HardAccuracy: 37.98%Submissions: 110K+Points: 8
Given an incomplete Sudoku configuration in terms of a 9x9  2-D interger square matrix, mat[][], the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed and cannot be changed.

Examples:

Input: mat[][] = 

Output:

Explanation: Each row, column and 3 x 3 box of the output matrix contains unique numbers.
Input: mat[][] = 

Output:

Explanation: Each row, column and 3 x 3 box of the output matrix contains unique numbers.
Constraints:
mat.size() = 9
mat[i].size() = 9
0 ≤ mat[i][j] ≤ 9



*/