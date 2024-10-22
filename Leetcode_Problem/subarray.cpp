/*

Sub-arrays with equal number of occurences
Difficulty: HardAccuracy: 57.94%Submissions: 11K+Points: 8
Given an array arr[] and two integers say, x and y, find the number of sub-arrays in which the number of occurrences of x is equal to the number of occurrences of y.

Examples:

Input: arr[] = [1, 2, 1] , x= 1 , y = 2
Output: 2
Explanation: The possible sub-arrays have same equal number of occurrences of x and y are:
1) [1, 2], x and y have same occurrence(1).
2) [2, 1], x and y have same occurrence(1).
Input: arr[] = [1, 2, 1] , x = 4 , y = 6
Output: 6
Explanation: The possible sub-arrays have same equal number of occurrences of x and y are:
1) [1], x and y have same occurrence(0).
2) [2], x and y have same occurrence(0).
3) [1], x and y have same occurrence(0).
4) [1, 2], x and y have same occurrence(0).
5) [2, 1], x and y have same occurrence(0).
6) [1, 2, 1], x and y have same occurrence(0).
Input: arr[] = [1, 2, 1] , x= 1 , y = 4
Output: 1
Explanation: The possible sub-array have same equal number of occurrences of x and y is: [2], x and y have same occurrence(0)
Constraints: 
1 <= arr.size() <= 106
1 <= arr[i], x, y<=106


*/
class Solution {
public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // HashMap to store frequency of count_diff
        unordered_map<int, int> count_map;
        int count_diff = 0;  // Difference between counts of x and y
        int result = 0;

        // Initialize the count_map with 0 count_diff seen once
        count_map[0] = 1;

        for (int num : arr) {
            // Update count_diff
            if (num == x) {
                count_diff++;
            } else if (num == y) {
                count_diff--;
            }

            // If count_diff has been seen before, add the number of occurrences
            result += count_map[count_diff];

            // Increment the count of this particular count_diff
            count_map[count_diff]++;
        }

        return result;
    }
};