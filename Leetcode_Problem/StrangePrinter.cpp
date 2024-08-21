/*

664. Strange Printer
Hard
Topics
Companies
There is a strange printer with the following two special properties:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.

 

Example 1:

Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
Example 2:

Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
 

Constraints:

1 <= s.length <= 100
s consists of lowercase English letters.
*/
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;  // Base case: A single character needs 1 turn
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = dp[i][j - 1] + 1;  // Start with the worst case: print s[i] to s[j-1] and then s[j]
                for (int k = i; k < j; ++k) {
                    if (s[k] == s[j]) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1]);
                    }
                }
            }
        }
        
        return dp[0][n - 1];
    }
};
