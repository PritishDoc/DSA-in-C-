/*
Max Circular Subarray Sum
Difficulty: HardAccuracy: 29.37%Submissions: 118K+Points: 8
Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

Examples:

Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
Output: 22
Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
Output: 23
Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
Input: arr[] = [-1, 40, -14, 7, 6, 5, -4, -1] 
Output: 52
Explanation: Circular Subarray [7, 6, 5, -4, -1, -1, 40] has the maximum sum, which is 52.
Constraints:
1 <= arr.size() <= 105
-104 <= arr[i] <= 104

*/
class Solution {
public:
    // Function to find the maximum circular subarray sum
    int circularSubarraySum(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Compute the total sum of the array
        int total_sum = 0;
        for (int num : arr) {
            total_sum += num;
        }

        // Step 2: Kadane's algorithm for max subarray sum (non-circular)
        int max_kadane = kadane(arr, false);

        // Step 3: Kadane's algorithm for min subarray sum
        int min_kadane = kadane(arr, true);

        // Step 4: Compute max_wrap
        int max_wrap = total_sum - min_kadane;

        // Step 5: Return the result
        // If all elements are negative, max_wrap will be 0, so return max_kadane
        if (max_wrap == 0) return max_kadane;

        return max(max_kadane, max_wrap);
    }

private:
    // Helper function to perform Kadane's algorithm
    int kadane(vector<int>& arr, bool find_min) {
        int result = find_min ? INT_MAX : INT_MIN;
        int current = find_min ? 0 : 0;

        for (int num : arr) {
            if (find_min) {
                current = min(current + num, num);
                result = min(result, current);
            } else {
                current = max(current + num, num);
                result = max(result, current);
            }
        }

        return result;
    }
};
