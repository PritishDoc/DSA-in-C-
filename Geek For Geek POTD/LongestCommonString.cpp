/*
Longest Common Substring
Difficulty: MediumAccuracy: 42.69%Submissions: 229K+Points: 4
You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: str1 = "ABCDGH", str2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.
Input: str1 = "ABC", str2 = "ACB"
Output: 1
Explanation: The longest common substrings are "A", "B", "C" all having length 1.
Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1<= str1.size(), str2.size()<=1000
Both strings may contain upper and lower case alphabets.
*/

#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int longestCommonSubstr(std::string str1, std::string str2) {
        int n = str1.size();
        int m = str2.size();
        int maxLength = 0;
        
        // Step 1: Create and initialize DP table
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        
        // Step 2: Fill the DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxLength = std::max(maxLength, dp[i][j]);
                }
            }
        }
        
        // Step 3: Return the result
        return maxLength;
    }
};
