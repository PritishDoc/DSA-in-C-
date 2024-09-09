/*


Code


Testcase
Test Result
Test Result
2326. Spiral Matrix IV
Medium
Topics
Companies
Hint
You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.

 

Example 1:


Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
Example 2:


Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.
 

Constraints:

1 <= m, n <= 105
1 <= m * n <= 105
The number of nodes in the list is in the range [1, m * n].
0 <= Node.val <= 1000
*/
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Initialize the matrix with -1
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        // Define the boundaries for the spiral traversal
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        
        // Traverse the matrix in spiral order
        while (head && top <= bottom && left <= right) {
            // Traverse from left to right along the top boundary
            for (int i = left; i <= right && head; ++i) {
                matrix[top][i] = head->val;
                head = head->next;
            }
            top++; // Move the top boundary down
            
            // Traverse from top to bottom along the right boundary
            for (int i = top; i <= bottom && head; ++i) {
                matrix[i][right] = head->val;
                head = head->next;
            }
            right--; // Move the right boundary left
            
            // Traverse from right to left along the bottom boundary
            for (int i = right; i >= left && head; --i) {
                matrix[bottom][i] = head->val;
                head = head->next;
            }
            bottom--; // Move the bottom boundary up
            
            // Traverse from bottom to top along the left boundary
            for (int i = bottom; i >= top && head; --i) {
                matrix[i][left] = head->val;
                head = head->next;
            }
            left++; // Move the left boundary right
        }
        
        return matrix;
    }
};