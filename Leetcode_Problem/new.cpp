/*

Count Inversions
Difficulty: MediumAccuracy: 16.93%Submissions: 592K+Points: 4
Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 10

*/
#include <vector>
using namespace std;

class Solution {
public:
    // Function to count inversions in the array.
    int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
        int i = left;     // Starting index for left subarray
        int j = mid + 1;  // Starting index for right subarray
        int k = left;     // Starting index to store sorted elements
        int count = 0;

        // Merge two subarrays and count inversions.
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                count += (mid - i + 1); // Count inversions
            }
        }

        // Copy remaining elements of left subarray, if any.
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy remaining elements of right subarray, if any.
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy sorted elements back to the original array.
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return count;
    }

    // Recursive function to count inversions using merge sort.
    int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
        int count = 0;

        if (left < right) {
            int mid = left + (right - left) / 2;

            // Count inversions in left and right subarrays
            count += mergeSortAndCount(arr, temp, left, mid);
            count += mergeSortAndCount(arr, temp, mid + 1, right);

            // Count split inversions
            count += mergeAndCount(arr, temp, left, mid, right);
        }

        return count;
    }

    int inversionCount(vector<int>& arr) {
        vector<int> temp(arr.size());
        return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
    }
};
