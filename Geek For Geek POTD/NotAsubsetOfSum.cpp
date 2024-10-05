/*


Not a subset sum
Difficulty: MediumAccuracy: 45.92%Submissions: 30K+Points: 4
Given a sorted array arr[] of positive integers, find the smallest positive integer such that it cannot be represented as the sum of elements of any subset of the given array set.

Examples:

Input: arr[] = [1, 2, 3]
Output: 7
Explanation: 7 is the smallest positive number for which no subset is there with sum 7.
Input: arr[] = [3, 6, 9, 10, 20, 28]
Output: 1
Explanation: 1 is the smallest positive number for which no subset is there with sum 1.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints
1 <= arr.size() <= 106
1 <= arr[i] <= 108
*/

class Solution {
public:
    long long findSmallest(vector<int> &arr) {
        long long smallest_missing = 1; // Start with the smallest number we can't form
        for (int i = 0; i < arr.size(); i++) {
            // If the current element is greater than smallest_missing, we found the answer
            if (arr[i] > smallest_missing) {
                break;
            }
            // Otherwise, we can form all sums up to smallest_missing + arr[i]
            smallest_missing += arr[i];
        }
        return smallest_missing;
    }
};