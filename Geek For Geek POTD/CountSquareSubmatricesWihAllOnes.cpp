/*
Count Square Submatrices with All Ones
Medium
Topics

Hint
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

*/
class Solution {
public:
    int countSquares(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int totalSquares = 0;
        
        // DP matrix to store the size of the largest square ending at each cell
        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
        
        // Fill the DP matrix based on the given conditions
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Only process cell if it is a 1
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        // For first row or first column, dp[i][j] is just matrix[i][j]
                        dp[i][j] = 1;
                    } else {
                        // Otherwise, use the min of the three neighbors plus one
                        dp[i][j] = std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    // Add the current dp[i][j] value to the total count
                    totalSquares += dp[i][j];
                }
            }
        }
        
        return totalSquares;
    }
};