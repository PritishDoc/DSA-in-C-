/*
Wildcard Pattern Matching
Difficulty: HardAccuracy: 31.13%Submissions: 70K+Points: 8
Given two strings pattern and str which may be of different size, You have to return 1 if the wildcard pattern i.e. pattern, matches with str else return 0. All characters of the string str and pattern always belong to the Alphanumeric characters.

The wildcard pattern can include the characters ? and *
‘?’ – matches any single character.
‘*’ – Matches any sequence of characters (including the empty sequence).

Note: The matching should cover the entire str (not partial str).

Examples:
Input: pattern = "ba*a?", str = "baaabab"
Output: 1
Explanation: replace '*' with "aab" and 
'?' with 'b'.
Input: pattern = "a*ab", str = "baaabab"
Output: 0
Explanation: Because in string pattern character 'a' at first position,
pattern and str can't be matched. 
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 <= length of(str, pattern) <= 200


*/
class Solution {
public:
    int wildCard(string pattern, string str) {
        int m = pattern.size();
        int n = str.size();

        // Create a DP table with (m+1) x (n+1) dimensions initialized to 0.
        vector<vector<int>> dp(m + 1, n + 1, 0);

        // Base case: Empty pattern matches with empty string.
        dp[0][0] = 1;

        // Handle patterns like '*', '**', etc., which can match with an empty string.
        for (int i = 1; i <= m; i++) {
            if (pattern[i - 1] == '*')
                dp[i][0] = dp[i - 1][0];
        }

        // Fill the DP table.
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (pattern[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else if (pattern[i - 1] == str[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        // The result is in dp[m][n].
        return dp[m][n];
    }
};
