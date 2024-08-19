/*

Code
Testcase
Test Result
Test Result
650. 2 Keys Keyboard
Medium
Topics
Companies
Hint
There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

 

Example 1:

Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Example 2:

Input: n = 1
Output: 0
 

Constraints:

1 <= n <= 1000
*/
class Solution {
public:
    int minSteps(int n) {
        // DP array to store the minimum number of operations
        vector<int> dp(n + 1, 0);
        
        // Start calculating from 2 to n
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;  // Maximum steps would be i (by only pasting one character at a time)
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    // if j is a factor, we check both j and i/j
                    dp[i] = min(dp[i], dp[j] + (i / j));
                    dp[i] = min(dp[i], dp[i / j] + j);
                }
            }
        }
        
        return dp[n];
    }
};
