/*

K Sized Subarray Maximum
Difficulty: MediumAccuracy: 26.04%Submissions: 329K+Points: 4
Given an array arr[] and an integer k. Find the maximum for each and every contiguous subarray of size k.

Examples:

Input: k = 3, arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6]
Output: [3, 3, 4, 5, 5, 5, 6] 
Explanation: 
1st contiguous subarray = [1 2 3] max = 3
2nd contiguous subarray = [2 3 1] max = 3
3rd contiguous subarray = [3 1 4] max = 4
4th contiguous subarray = [1 4 5] max = 5
5th contiguous subarray = [4 5 2] max = 5
6th contiguous subarray = [5 2 3] max = 5
7th contiguous subarray = [2 3 6] max = 6

Input: k = 4, arr[] = [8, 5, 10, 7, 9, 4, 15, 12, 90, 13]
Output: [10, 10, 10, 15, 15, 90, 90]
Explanation: 
1st contiguous subarray = [8 5 10 7], max = 10
2nd contiguous subarray = [5 10 7 9], max = 10
3rd contiguous subarray = [10 7 9 4], max = 10
4th contiguous subarray = [7 9 4 15], max = 15
5th contiguous subarray = [9 4 15 12], max = 15
6th contiguous subarray = [4 15 12 90], max = 90
7th contiguous subarray = {15 12 90 13}, max = 90
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(k)

Constraints:
1 ≤ sizeof(arr) ≤ 106
1 ≤ k ≤ sizeof(arr)
0 ≤ arr[i] ≤ 109
*/

class Solution {
  public:
    // Function to find the maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int>& arr) {
        deque<int> dq; // Store indices of useful elements for the current window
        vector<int> result; // To store the maximum of each subarray
        
        // Traverse the array
        for (int i = 0; i < arr.size(); ++i) {
            // Remove elements from the front if they are out of the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // Remove elements from the back if they are smaller than the current element
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            
            // Add the current element's index to the deque
            dq.push_back(i);
            
            // Start adding to result after the first window is formed
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]); // Maximum of the current window
            }
        }
        
        return result;
    }
};