/*

Minimum number of deletions and insertions
Difficulty: MediumAccuracy: 65.29%Submissions: 56K+Points: 4
Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Examples :

Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion.
p and h deleted from heap. Then, p is inserted at the beginning.
One thing to note, though p was required yet it was removed/deleted first from its position and then it is inserted to some other position. Thus, p contributes one to the deletion_count and one to the insertion_count.
Input : str1 = "geeksforgeeks", str2 = "geeks"
Output: 8
Explanation: 8 deletions, i.e. remove all characters of the string "forgeeks".
Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)

Constraints:
1 ≤ |str1|, |str2| ≤ 1000
All the characters are lowercase English alphabets

*/
class Solution {
public:
    int minOperations(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        
        // Create a 2D DP array to store the length of LCS
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        // Fill the DP array
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // Length of LCS
        int LCS_length = dp[m][n];
        
        // Calculate the minimum number of operations
        int deletions = m - LCS_length;
        int insertions = n - LCS_length;
        
        return deletions + insertions;
    }
};
