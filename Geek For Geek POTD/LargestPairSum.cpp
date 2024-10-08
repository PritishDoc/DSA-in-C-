/*

Largest Pair Sum
Difficulty: EasyAccuracy: 60.24%Submissions: 19K+Points: 2
Find the largest pair sum in an array of distinct integers.

Examples :

Input: arr[] = [12, 34, 10, 6, 40]
Output: 74
Explanation: Sum of 34 and 40 is the largest, i.e, 34 + 40 = 74.
Input: arr[] = [10, 20, 30]
Output: 50
Explanation: 20 + 30 = 50.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
*/
class Solution {
public:
    int pairsum(std::vector<int> &arr) {
        int first_max = INT_MIN;
        int second_max = INT_MIN;
        
        // Traverse the array to find the two largest elements
        for (int num : arr) {
            if (num > first_max) {
                second_max = first_max;  // Update second_max before changing first_max
                first_max = num;
            } else if (num > second_max) {
                second_max = num;
            }
        }
        
        // Return the sum of the two largest elements
        return first_max + second_max;
    }
};