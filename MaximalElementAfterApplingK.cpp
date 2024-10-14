/*
Maximal Score After Applying K Operations

Hint
You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.

In one operation:

choose an index i such that 0 <= i < nums.length,
increase your score by nums[i], and
replace nums[i] with ceil(nums[i] / 3).
Return the maximum possible score you can attain after applying exactly k operations.

The ceiling function ceil(val) is the least integer greater than or equal to val.

 

Example 1:

Input: nums = [10,10,10,10,10], k = 5
Output: 50
Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.
Example 2:

Input: nums = [1,10,3,3,3], k = 3
Output: 17
Explanation: You can do the following operations:
Operation 1: Select i = 1, so nums becomes [1,4,3,3,3]. Your score increases by 10.
Operation 2: Select i = 1, so nums becomes [1,2,3,3,3]. Your score increases by 4.
Operation 3: Select i = 2, so nums becomes [1,1,1,3,3]. Your score increases by 3.
The final score is 10 + 4 + 3 = 17.
 

Constraints:

1 <= nums.length, k <= 105
1 <= nums[i] <= 109
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // Using max heap (priority queue) to always extract the largest element
        priority_queue<long long> maxHeap(nums.begin(), nums.end());
        long long score = 0;

        for (int i = 0; i < k; ++i) {
            // Get the largest element from the heap
            long long largest = maxHeap.top();
            maxHeap.pop();
            
            // Add the largest element to the score
            score += largest;
            
            // Replace it with ceil(largest / 3) and push it back to the heap
            long long newVal = (largest + 2) / 3;  // ceil operation
            maxHeap.push(newVal);
        }

        return score;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {10, 10, 10, 10, 10};
    int k1 = 5;
    cout << "Max Score: " << sol.maxKelements(nums1, k1) << endl;  // Output: 50

    // Example 2
    vector<int> nums2 = {1, 10, 3, 3, 3};
    int k2 = 3;
    cout << "Max Score: " << sol.maxKelements(nums2, k2) << endl;  // Output: 17

    return 0;
}
