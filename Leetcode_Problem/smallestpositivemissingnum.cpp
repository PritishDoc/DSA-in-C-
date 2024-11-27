/*


Smallest Positive Missing Number
Difficulty: MediumAccuracy: 25.13%Submissions: 365K+Points: 4
You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

Note: Positive number starts from 1. The array can have negative integers too.

Examples:

Input: arr[] = [2, -3, 4, 1, 1, 7]
Output: 3
Explanation: Smallest positive missing number is 3.
Input: arr[] = [5, 3, 2, 5, 1]
Output: 4
Explanation: Smallest positive missing number is 4.
Input: arr[] = [-8, 0, -1, -4, -3]
Output: 1
Explanation: Smallest positive missing number is 1.
Constraints:  
1 <= arr.size() <= 105
-106 <= arr[i] <= 10

*/
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Place each number in its correct position
        for (int i = 0; i < n; ++i) {
            while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // Step 2: Find the first index where the value is not correct
        for (int i = 0; i < n; ++i) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }

        // If all values are in the correct position, return n + 1
        return n + 1;
    }
};
