/*
Equilibrium Point
Difficulty: EasyAccuracy: 28.13%Submissions: 613K+Points: 2
Given an array of integers arr[], the task is to find the first equilibrium point in the array.

The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists. 

Examples:

Input: arr[] = [1, 2, 0, 3]
Output: 2 
Explanation: The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 0 + 3 = 3.
Input: arr[] = [1, 1, 1, 1]
Output: -1
Explanation: There is no equilibrium index in the array.
Input: arr[] = [-7, 1, 5, 2, -4, 3, 0]
Output: 3
Explanation: The sum of left of index 3 is -7 + 1 + 5 = -1 and sum on right of index 3 is -4 + 3 + 0 = -1.
Constraints:
3 <= arr.size() <= 106
-109 <= arr[i] <= 109

*/
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int totalSum = 0; // Total sum of the array
        int leftSum = 0;  // Sum of elements to the left of the current index

        // Calculate total sum of the array
        for (int num : arr) {
            totalSum += num;
        }

        // Traverse the array to find the equilibrium index
        for (int i = 0; i < arr.size(); i++) {
            // Right sum is totalSum - leftSum - arr[i]
            int rightSum = totalSum - leftSum - arr[i];

            // Check if leftSum equals rightSum
            if (leftSum == rightSum) {
                return i; // Return the index
            }

            // Update leftSum for the next iteration
            leftSum += arr[i];
        }

        // If no equilibrium index is found, return -1
        return -1;
    }
};
