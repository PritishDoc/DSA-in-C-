/*


 Count the Number of Fair Pairs

Hint
Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
 

Example 1:

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
Example 2:

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
 

Constraints:

1 <= nums.length <= 105
nums.length == n
-109 <= nums[i] <= 109
-109 <= lower <= upper <= 109
*/
#include <vector>
#include <algorithm>

class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        // Step 1: Sort the array
        std::sort(nums.begin(), nums.end());
        
        long long count = 0;
        int n = nums.size();
        
        // Step 2: Iterate through each element in the array
        for (int i = 0; i < n; ++i) {
            // Step 3: Find the range of indices j > i where lower <= nums[i] + nums[j] <= upper
            int low = std::lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int high = std::upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() - 1;
            
            // Step 4: Count the valid pairs for this element
            if (low <= high) {
                count += (high - low + 1);
            }
        }
        
        return count;
    }
};
