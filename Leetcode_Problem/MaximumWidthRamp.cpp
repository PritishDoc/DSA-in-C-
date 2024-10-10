/*
Maximum Width Ramp
Medium
Topics
Companies
A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.

Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.

 

Example 1:

Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
Example 2:

Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
 

Constraints:

2 <= nums.length <= 5 * 104
0 <= nums[i] <= 5 * 104

*/
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;  // Monotonic decreasing stack (stores indices)
        int n = nums.size();
        
        // Step 1: Build a decreasing stack of indices
        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }
        
        int maxWidth = 0;
        
        // Step 2: Traverse from the end to find the maximum width ramp
        for (int j = n - 1; j >= 0; --j) {
            while (!st.empty() && nums[st.top()] <= nums[j]) {
                // Calculate width and update maxWidth
                maxWidth = max(maxWidth, j - st.top());
                st.pop();  // We pop because this index has been used
            }
        }
        
        return maxWidth;
    }
};