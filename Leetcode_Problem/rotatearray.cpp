/*

Rotate Array
Difficulty: MediumAccuracy: 37.06%Submissions: 374K+Points: 4
Given an unsorted array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.

Examples :

Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.
Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.
Input: arr[] = [7, 3, 9, 1], d = 9
Output: [3, 9, 1, 7]
Explanation: when we rotate 9 times, we'll get 3 9 1 7 as resultant array.
Constraints:
1 <= arr.size(), d <= 105
0 <= arr[i] <= 105
*/
class Solution {
public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        // Normalize d to ensure it is within the array bounds
        d = d % n;
        
        // Step 1: Reverse the first d elements
        reverse(arr.begin(), arr.begin() + d);
        
        // Step 2: Reverse the remaining n - d elements
        reverse(arr.begin() + d, arr.end());
        
        // Step 3: Reverse the entire array
        reverse(arr.begin(), arr.end());
    }
};