/*
Edit Distance
Difficulty: HardAccuracy: 35.14%Submissions: 199K+Points: 8
Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
Examples:

Input: str1 = "geek", srt2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e'.
Input : str1 = "gfg", str2 = "gfg"
Output: 0
Explanation: Both strings are same.
Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)

Constraints:
1 ≤ str1.length(), str2.length() ≤ 100
Both the strings are in lowercase.


*/
class Solution {
public:
    int editDistance(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        // Base cases
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        
        // Fill dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j] + 1, // Remove
                                    dp[i][j - 1] + 1, // Insert
                                    dp[i - 1][j - 1] + 1}); // Replace
                }
            }
        }
        
        return dp[m][n];
    }
};