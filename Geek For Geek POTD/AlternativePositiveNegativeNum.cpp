/*
Alternate positive and negative numbers
Difficulty: EasyAccuracy: 33.86%Submissions: 192K+Points: 2
Given an unsorted array arr containing both positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
Note: Array should start with a positive number and 0 (zero) should be considered a positive element.

Examples:

Input: arr[] = [9, 4, -2, -1, 5, 0, -5, -3, 2]
Output: 9 -2 4 -1 5 -5 0 -3 2
Explanation: Positive elements : [9,4,5,0,2]
Negative elements : [-2,-1,-5,-3]
As we need to maintain the relative order of postive elements and negative elements we will pick each element from the positive and negative and will store them. If any of the positive and negative numbersare completed. we will continue with the remaining signed elements.
The output is 9,-2,4,-1,5,-5,0,-3,2.
Input: arr[] = [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
Output: 5 -5 2 -2 4 -8 7 1 8 0
Explanation : Positive elements : [5,2,4,7,1,8,0]
Negative elements : [-5,-2,-8]
The output is 5, -5, 2, -2, 4, -8, 7, 1, 8, 0.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ arr.size() ≤ 107
-106 ≤ arr[i] ≤ 107

*/
class Solution {
public:
    void rearrange(vector<int> &arr) {
        vector<int> pos, neg;
        
        // Step 1: Separate positive and negative numbers
        for (int num : arr) {
            if (num >= 0) {
                pos.push_back(num);  // consider 0 as positive
            } else {
                neg.push_back(num);
            }
        }
        
        // Step 2: Merge positive and negative numbers alternately
        int i = 0, j = 0, k = 0;
        bool turnPositive = true;  // To track whether to insert positive or negative
        
        while (i < pos.size() && j < neg.size()) {
            if (turnPositive) {
                arr[k++] = pos[i++];
            } else {
                arr[k++] = neg[j++];
            }
            turnPositive = !turnPositive;  // Alternate the turns
        }
        
        // Step 3: If any positive numbers are left, append them
        while (i < pos.size()) {
            arr[k++] = pos[i++];
        }
        
        // Step 4: If any negative numbers are left, append them
        while (j < neg.size()) {
            arr[k++] = neg[j++];
        }
    }
};
