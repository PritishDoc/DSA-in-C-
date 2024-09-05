/*
Missing in Array
Difficulty: EasyAccuracy: 29.59%Submissions: 1.2MPoints: 2
Given an array arr of size n−1 that contains distinct integers in the range of 1 to n (inclusive), find the missing element. The array is a permutation of size n with one element missing. Return the missing element.

Examples:

Input: n = 5, arr[] = [1,2,3,5]
Output: 4
Explanation : All the numbers from 1 to 5 are present except 4.
Input: n = 2, arr[] = [1]
Output: 2
Explanation : All the numbers from 1 to 2 are present except 2.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ n
*/
class Solution {
public:
    int missingNumber(int n, vector<int>& arr) {
        // Calculate the expected sum of numbers from 1 to n
        int expected_sum = n * (n + 1) / 2;
        
        // Calculate the sum of elements in the array
        int sum_of_array = 0;
        for (int num : arr) {
            sum_of_array += num;
        }
        
        // The missing number is the difference between expected_sum and sum_of_array
        return expected_sum - sum_of_array;
    }
};