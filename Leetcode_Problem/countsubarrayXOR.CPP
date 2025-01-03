/*
Count Subarrays with given XOR
Difficulty: MediumAccuracy: 58.86%Submissions: 17K+Points: 4
Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

Examples: 

Input: arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.
Input: arr[] = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.
Input: arr[] = [1, 1, 1, 1], k = 0
Output: 4
Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].
Constraints:

1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤105
0 ≤ k ≤ 105


*/
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> freq; // To store frequency of prefixXor
        int prefixXor = 0;
        long count = 0;
        
        freq[0] = 1; // Initialize for subarrays starting from index 0
        
        for (int num : arr) {
            prefixXor ^= num; // Update prefixXor
            
            // Check if prefixXor ⊕ k exists in the map
            int target = prefixXor ^ k;
            if (freq.find(target) != freq.end()) {
                count += freq[target];
            }
            
            // Update frequency of the current prefixXor
            freq[prefixXor]++;
        }
        
        return count;
    }
};
