/*
Largest subarray of 0's and 1's
Difficulty: EasyAccuracy: 32.96%Submissions: 103K+Points: 2
Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.

Examples:

Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
Output: 6
Explanation: arr[1...6] is the longest subarray with three 0s and three 1s.
Input: arr[] = [0, 0, 1, 1, 0]
Output: 4
Explnation: arr[0...3] or arr[1...4] is the longest subarray with two 0s and two 1s.
Input: arr[] = [0]
Output: 0
Explnation: There is no subarray with an equal number of 0s and 1s.
Constraints:
1 <= arr.size() <= 105
0 <= arr[i] <= 1

*/
class Solution {
public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> sumIndexMap; // Map to store first occurrence of cumulative sum
        int maxLength = 0;
        int cumulativeSum = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            // Replace 0 with -1
            cumulativeSum += (arr[i] == 0) ? -1 : 1;
            
            // If cumulativeSum is 0, we found a subarray from index 0 to i
            if (cumulativeSum == 0) {
                maxLength = i + 1;
            }
            
            // Check if this cumulativeSum has been seen before
            if (sumIndexMap.find(cumulativeSum) != sumIndexMap.end()) {
                // Update maxLength if the subarray is longer
                maxLength = max(maxLength, i - sumIndexMap[cumulativeSum]);
            } else {
                // Store the first occurrence of the cumulativeSum
                sumIndexMap[cumulativeSum] = i;
            }
        }
        
        return maxLength;
    }
};
