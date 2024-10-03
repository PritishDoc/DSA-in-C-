/*

Make Sum Divisible by P
Medium
Topics
Companies
Hint
Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

 

Example 1:

Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
Example 2:

Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
Example 3:

Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= p <= 109
*/
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = totalSum % p;

        if (rem == 0) return 0;  // No need to remove anything, already divisible by p

        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1;  // We start with the prefix sum of 0 at index -1
        int prefixSum = 0;
        int minLength = n;  // Initialize to maximum possible size

        for (int i = 0; i < n; ++i) {
            prefixSum = (prefixSum + nums[i]) % p;

            // We want to find a prefix sum that satisfies: (prefixSum - rem) % p == 0
            int target = (prefixSum - rem + p) % p;

            if (prefixMap.find(target) != prefixMap.end()) {
                minLength = min(minLength, i - prefixMap[target]);
            }

            // Store the latest occurrence of prefixSum % p
            prefixMap[prefixSum] = i;
        }

        // If we didn't find any valid subarray, return -1
        return minLength == n ? -1 : minLength;
    }
};