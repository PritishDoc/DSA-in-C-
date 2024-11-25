/*
Difficulty: MediumAccuracy: 18.09%Submissions: 398K+Points: 4
Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr.

Note: It is guaranteed that the output fits in a 32-bit integer.

Examples

Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.
Input: arr[] = [-1, -3, -10, 0, 6]
Output: 30
Explanation: The subarray with maximum product is {-3, -10} with product = (-3) * (-10) = 30.
Input: arr[] = [2, 3, 4] 
Output: 24 
Explanation: For an array with all positive elements, the result is product of all elements. 
Constraints:
1 ≤ arr.size() ≤ 106
-10  ≤  arr[i]  ≤  10

*/
class Solution {
public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int maxProduct = arr[0]; // Global maximum product
        int maxEndingHere = arr[0]; // Local maximum product ending at the current position
        int minEndingHere = arr[0]; // Local minimum product ending at the current position

        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) {
                // Swap maxEndingHere and minEndingHere when a negative number is encountered
                swap(maxEndingHere, minEndingHere);
            }

            // Update the local maximum and minimum products
            maxEndingHere = max(arr[i], maxEndingHere * arr[i]);
            minEndingHere = min(arr[i], minEndingHere * arr[i]);

            // Update the global maximum product
            maxProduct = max(maxProduct, maxEndingHere);
        }

        return maxProduct;
    }
};