/*
Find All Triplets with Zero Sum
Difficulty: MediumAccuracy: 50.36%Submissions: 41K+Points: 4
Given an array arr[], find all possible triplets i, j, k in the arr[] whose sum of elements is equals to zero. 
Returned triplet should also be internally sorted i.e. i<j<k.

Examples:

Input: arr[] = [0, -1, 2, -3, 1]
Output: [[0, 1, 4], [2, 3, 4]]
Explanation: Triplets with sum 0 are:
arr[0] + arr[1] + arr[4] = 0 + (-1) + 1 = 0
arr[2] + arr[3] + arr[4] = 2 + (-3) + 1 = 0
Input: arr[] = [1, -2, 1, 0, 5]
Output: [[0, 1, 2]]
Explanation: Only triplet which satisfies the condition is arr[0] + arr[1] + arr[2] = 1 + (-2) + 1 = 0
Input: arr[] = [2, 3, 1, 0, 5]
Output: [[]]
Explanation: There is no triplet with sum 0.
Constraints:
3 <= arr.size() <= 103
-104 <= arr[i] <= 104

*/
class Solution {
Wrong Answer. !!!
Ask Yogi Bot
Possibly your code does not work correctly for multiple test-cases (TCs).

The first test case where your code failed:

Test Cases Passed: 
8 /1110
For Input: 
-1 0 1 2 -1 -4
Your Code's output is: 
0 1 2
0 3 4
It's Correct output is: 
0 1 2
0 3 4
1 2 4
Output Difference
0 1 2
0 3 4
1 2 4