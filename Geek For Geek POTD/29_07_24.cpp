/*
Row with max 1s
Difficulty: MediumAccuracy: 33.09%Submissions: 276K+Points: 4
Given a boolean 2D array, consisting of only 1's and 0's, where each row is sorted. Return the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

Examples:

Input: arr[][] = [[0, 1, 1, 1],
               [0, 0, 1, 1],
               [1, 1, 1, 1],
               [0, 0, 0, 0]]
Output: 2
Explanation: Row 2 contains 4 1's (0-based indexing).
Input: arr[][] = [[0, 0], 
               [1, 1]]
Output: 1
Explanation: Row 1 contains 2 1's (0-based indexing).
Expected Time Complexity: O(n+m)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ number of rows, number of columns ≤ 103
0 ≤ arr[i][j] ≤ 1 
*/
class Solution {
public:
    int rowWithMax1s(vector<vector<int>>& arr) {
        int maxRow = -1; // Initialize the index of the row with max 1s
        int maxCount = 0; // Initialize the max count of 1s

        for (int i = 0; i < arr.size(); ++i) {
            int index = first(arr[i], 0, arr[i].size() - 1);
            if (index != -1) { // Check if there's at least one 1 in the row
                int count = arr[i].size() - index; // Count of 1s in the current row
                if (count > maxCount) {
                    maxCount = count;
                    maxRow = i;
                }
            }
        }

        return maxRow;
    }

private:
    int first(vector<int>& row, int low, int high) {
        int idx = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == 1) {
                idx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return idx;
    }
};
