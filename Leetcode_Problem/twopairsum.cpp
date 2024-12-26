/*
Two Sum - Pair with Given Sum
Difficulty: EasyAccuracy: 30.61%Submissions: 326K+Points: 2
Given an array arr[] of positive integers and another integer target. Determine if there exists two distinct indices such that the sum of there elements is equals to target.

Examples:

Input: arr[] = [1, 4, 45, 6, 10, 8], target = 16
Output: true
Explanation: arr[3] + arr[4] = 6 + 10 = 16.
Input: arr[] = [1, 2, 4, 3, 6], target = 11
Output: false
Explanation: None of the pair makes a sum of 11.
Constraints:
1 ≤ arr.size ≤ 105
1 ≤ arr[i] ≤ 105
1 ≤ target ≤ 2*1

*/
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> numMap; // To store numbers and their indices

        for (int i = 0; i < arr.size(); i++) {
            int complement = target - arr[i];

            // Check if the complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                return true;
            }

            // Add the current number to the map
            numMap[arr[i]] = i;
        }

        // No pair found
        return false;
    }
};
