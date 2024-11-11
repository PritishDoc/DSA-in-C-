/*
Make array elements unique
Difficulty: MediumAccuracy: 51.43%Submissions: 45K+Points: 4
Given an array arr[ ], your task is to find the minimum number of increment operations required to make all the elements of the array unique. i.e.- no value in the array should occur more than once. In one operation, a value can be incremented by 1 only.

Examples :

Input: arr[] = [1, 2, 2]
Output: 1
Explanation: If we increase arr[2] by 1 then the resulting array becomes {1, 2, 3} and has all unique values.Hence, the answer is 1 in this case.
Input: arr[] = [1, 1, 2, 3]
Output: 3
Explanation: If we increase arr[0] by 3, then all array elements will be unique. Hence, the answer is 3 in this case.
Input: arr[] = [5, 4, 3, 2, 1]
Output: 0
Explanation: All elements are unique.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106

*/
class Solution {
public:
    int minIncrements(std::vector<int>& arr) {
        // Step 1: Sort the array
        std::sort(arr.begin(), arr.end());
        
        int increments = 0;
        
        // Step 2: Traverse the array and make each element unique
        for (int i = 1; i < arr.size(); i++) {
            // If current element is not greater than the previous, we need to increment it
            if (arr[i] <= arr[i - 1]) {
                int requiredValue = arr[i - 1] + 1;
                increments += requiredValue - arr[i];
                arr[i] = requiredValue;  // Update the current element to be unique
            }
        }
        
        return increments;

        
    }
};