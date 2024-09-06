/*

Kadane's Algorithm
Difficulty: MediumAccuracy: 36.28%Submissions: 962K+Points: 4
Given an integer array arr[]. Find the contiguous sub-array(containing at least one number) that has the maximum sum and return its sum.

Examples:

Input: arr[] = [1, 2, 3, -2, 5]
Output: 9
Explanation: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.
Input: arr[] = [-1, -2, -3, -4]
Output: -1
Explanation: Max subarray sum is -1 of element (-1)
Input: arr[] = [5, 4, 7]
Output: 16
Explanation: Max subarray sum is 16 of element (5, 4, 7)
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 105
-107 ≤ arr[i] ≤ 107

*/
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(std::vector<int> &arr) {
        int n = arr.size();
        
        // Initialize variables to store the maximum sum and current subarray sum
        int maxSum = arr[0];
        int currentSum = arr[0];
        
        // Traverse the array starting from the second element
        for (int i = 1; i < n; i++) {
            // Update the current subarray sum
            currentSum = std::max(arr[i], currentSum + arr[i]);
            
            // Update the maximum sum found so far
            maxSum = std::max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};