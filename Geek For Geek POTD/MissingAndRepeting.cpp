/*
Missing And Repeating
Difficulty: MediumAccuracy: 24.83%Submissions: 499K+Points: 4
Given an unsorted array arr of of positive integers. One number 'A' from set {1, 2,....,n} is missing and one number 'B' occurs twice in array. Find numbers A and B.

Examples

Input: arr[] = [2, 2]
Output: 2 1
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ n ≤ 105
1 ≤ arr[i] ≤ n
*/

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int repeating = -1, missing = -1;

        // Step 1: Find the repeating number
        for (int i = 0; i < n; i++) {
            int index = abs(arr[i]) - 1;
            if (arr[index] < 0) {
                repeating = abs(arr[i]);  // This is the repeating number
            } else {
                arr[index] = -arr[index]; // Mark as visited
            }
        }

        // Step 2: Find the missing number
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                missing = i + 1;  // Missing number is i+1
                break;
            }
        }

        return {repeating, missing};
    }
};