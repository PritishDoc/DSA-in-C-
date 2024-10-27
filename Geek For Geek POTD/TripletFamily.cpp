/*
Triplet Family
Difficulty: BasicAccuracy: 50.0%Submissions: 30K+Points: 1
Given an array arr of integers. Find whether three numbers are such that the sum of two elements equals the third element.

Example:

Input: arr[] = [1, 2, 3, 4, 5]
Output: true
Explanation: The pair (1, 2) sums to 3.
Input: arr[] = [5, 3, 4]
Output: false
Explanation: No triplets satisfy the condition.
Expected Time Complexity: O(n2)
Expected Auxilary Space: O(1)

Constraints:
1 <= arr.size() <= 103
0 <= arr[i] <= 105

*/
class Solution {
public:
    bool findTriplet(std::vector<int>& arr) {
        int n = arr.size();
        
        // Sort the array to use the two-pointer technique
        std::sort(arr.begin(), arr.end());

        // Traverse the array, considering each element as the target sum
        for (int i = 0; i < n; i++) {
            int target = arr[i];
            int left = 0;
            int right = n - 1;
            
            // Find if there exists two elements whose sum is equal to target
            while (left < right) {
                // Skip the target element itself
                if (left == i) left++;
                else if (right == i) right--;
                else {
                    int sum = arr[left] + arr[right];
                    
                    if (sum == target) {
                        return true; // Found the triplet
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return false; // No such triplet found
    }
};