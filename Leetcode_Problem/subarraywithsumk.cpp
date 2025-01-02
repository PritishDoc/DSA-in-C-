/*

Subarrays with sum K
Difficulty: MediumAccuracy: 49.74%Submissions: 57K+Points: 4
Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.

Examples:

Input: arr = [10, 2, -2, -20, 10], k = -10
Output: 3
Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.
Input: arr = [9, 4, 20, 3, 10, 5], k = 33
Output: 2
Explaination: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33.
Input: arr = [1, 3, 5], k = 0
Output: 0
Explaination: No subarray with 0 sum.
Constraints:

1 ≤ arr.size() ≤ 105
-103 ≤ arr[i] ≤ 103
-107 ≤ k ≤ 10

*/
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int currentSum = 0;
        int count = 0;

        // Initialize the hash map with 0 sum frequency as 1
        prefixSumCount[0] = 1;

        for (int num : arr) {
            currentSum += num;

            // Check if there is a prefix sum that satisfies the condition
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }

            // Update the frequency of the current sum
            prefixSumCount[currentSum]++;
        }

        return count;
    }
};
