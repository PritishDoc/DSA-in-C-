/*
Find K-th Smallest Pair Distance

Hint
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

 

Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Example 2:

Input: nums = [1,1,1], k = 2
Output: 0
Example 3:

Input: nums = [1,6,1], k = 3
Output: 5
 
*/

class Solution {
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        // Step 1: Sort the array
        std::sort(nums.begin(), nums.end());
        
        // Step 2: Define the binary search range
        int low = 0;
        int high = nums.back() - nums.front();
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Step 3: Count the number of pairs with distance <= mid
            int count = 0;
            for (int i = 0, j = 0; i < nums.size(); ++i) {
                while (j < nums.size() && nums[j] - nums[i] <= mid) {
                    ++j;
                }
                count += j - i - 1;
            }
            
            // Step 4: Adjust the binary search range based on count
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        // Step 5: Return the result
        return low;
    }
};