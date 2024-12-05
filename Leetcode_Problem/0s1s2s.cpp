/*
Sort 0s, 1s and 2s
Difficulty: EasyAccuracy: 50.58%Submissions: 722K+Points: 2
Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

Examples:

Input: arr[] = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.
Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.
Constraints:
1 <= arr.size() <= 106
0 <= arr[i] <= 2



*/
#include <vector>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {
        int low = 0, mid = 0, high = arr.size() - 1;

        while (mid <= high) {
            if (arr[mid] == 0) {
                // Swap with low pointer and increment both
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } else if (arr[mid] == 1) {
                // Leave 1 in place, just move mid forward
                mid++;
            } else { // arr[mid] == 2
                // Swap with high pointer and decrement high
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};
