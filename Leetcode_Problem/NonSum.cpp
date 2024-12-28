/*



Maximum Sum of 3 Non-Overlapping Subarrays
Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

 

Example 1:

Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Example 2:

Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
Output: [0,2,4]
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i] < 216
1 <= k <= floor(nums.length / 3)
*/
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n - k + 1, 0); // sum of each subarray of length k
        vector<int> left(n - k + 1, 0); // best left subarray index
        vector<int> right(n - k + 1, 0); // best right subarray index
        vector<int> result(3, 0);
        
        // Step 1: Compute the sum of subarrays of length k
        int currSum = 0;
        for (int i = 0; i < n; ++i) {
            currSum += nums[i];
            if (i >= k) currSum -= nums[i - k];
            if (i >= k - 1) sum[i - k + 1] = currSum;
        }
        
        // Step 2: Fill the left array
        int bestLeft = 0;
        for (int i = 0; i < sum.size(); ++i) {
            if (sum[i] > sum[bestLeft]) bestLeft = i;
            left[i] = bestLeft;
        }
        
        // Step 3: Fill the right array
        int bestRight = sum.size() - 1;
        for (int i = sum.size() - 1; i >= 0; --i) {
            if (sum[i] >= sum[bestRight]) bestRight = i; // >= for lexicographical order
            right[i] = bestRight;
        }
        
        // Step 4: Find the maximum sum of three subarrays
        int maxSum = 0;
        for (int j = k; j < sum.size() - k; ++j) {
            int i = left[j - k];
            int l = right[j + k];
            int totalSum = sum[i] + sum[j] + sum[l];
            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {i, j, l};
            }
        }
        
        return result;
    }
};
