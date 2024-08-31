/*
N-Queen Problem
Difficulty: HardAccuracy: 35.43%Submissions: 84K+Points: 8
The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].



Examples:

Input: 1
Output: [1]
Explaination: Only one queen can be placed in the single cell available.
Input: 4
Output: [[2 4 1 3 ],[3 1 4 2 ]]
Explaination: These are the 2 possible solutions.
Expected Time Complexity: O(n!)
Expected Auxiliary Space: O(n2) 

Constraints:

*/
class Solution {
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> result;
        vector<int> board(n, 0);  // This will store the row positions of queens in each column
        solve(0, n, board, result);
        return result;
    }

private:
    void solve(int col, int n, vector<int>& board, vector<vector<int>>& result) {
        if (col == n) {
            result.push_back(board);
            return;
        }
        
        for (int row = 1; row <= n; ++row) {
            if (isSafe(row, col, board)) {
                board[col] = row;  // Place the queen in the current row
                solve(col + 1, n, board, result);
                board[col] = 0;  // Backtrack
            }
        }
    }
    
    bool isSafe(int row, int col, vector<int>& board) {
        for (int prevCol = 0; prevCol < col; ++prevCol) {
            int prevRow = board[prevCol];
            // Check if another queen is in the same row or diagonal
            if (prevRow == row || abs(prevRow - row) == abs(prevCol - col)) {
                return false;
            }
        }
        return true;
    }
};