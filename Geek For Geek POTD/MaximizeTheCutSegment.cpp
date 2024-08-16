/*
Maximize The Cut Segments
Difficulty: MediumAccuracy: 24.29%Submissions: 226K+Points: 4
Given an integer n denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum. Return the maximum number of cut segments possible.

Note: if no segment can be cut then return 0.

Examples:

Input: n = 4, x = 2, y = 1, z = 1
Output: 4
Explanation: Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.
Input: n = 5, x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2.
Expected Time Complexity : O(n)
Expected Auxiliary Space: O(n)

Constraints
1 <= n, x, y, z <= 104


*/

class Solution
{
    public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Initialize a dp array of size n+1 with all elements as -1.
        vector<int> dp(n + 1, -1);
        
        // Base case: dp[0] = 0, since 0 length can be obtained with 0 cuts.
        dp[0] = 0;
        
        // Iterate over all lengths from 1 to n.
        for (int i = 1; i <= n; ++i) {
            // If it's possible to cut a piece of length x.
            if (i >= x && dp[i - x] != -1) {
                dp[i] = max(dp[i], dp[i - x] + 1);
            }
            // If it's possible to cut a piece of length y.
            if (i >= y && dp[i - y] != -1) {
                dp[i] = max(dp[i], dp[i - y] + 1);
            }
            // If it's possible to cut a piece of length z.
            if (i >= z && dp[i - z] != -1) {
                dp[i] = max(dp[i], dp[i - z] + 1);
            }
        }
        
        // If dp[n] is still -1, it means no valid cuts could be made, so return 0.
        return dp[n] == -1 ? 0 : dp[n];
    }
};
