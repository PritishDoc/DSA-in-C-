/*

Product array puzzle
Difficulty: EasyAccuracy: 33.46%Submissions: 215K+Points: 2
Given an array nums[], construct a Product Array nums[] such that nums[i] is equal to the product of all the elements of nums except nums[i].

Examples:

Input: nums[] = [10, 3, 5, 6, 2]
Output: [180, 600, 360, 300, 900]
Explanation: For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
Input: nums[] = [12,0]
Output: [0, 12]
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= nums.size() <= 1000
0 <= nums[i] <= 200
nums[i] may contain duplicates.



*/

class Solution {
public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n = nums.size();
        
        // Initialize the left and right product arrays
        vector<long long int> leftProducts(n, 1);
        vector<long long int> rightProducts(n, 1);
        vector<long long int> result(n, 1);
        
        // Fill leftProducts array
        for (int i = 1; i < n; ++i) {
            leftProducts[i] = leftProducts[i-1] * nums[i-1];
        }
        
        // Fill rightProducts array
        for (int i = n - 2; i >= 0; --i) {
            rightProducts[i] = rightProducts[i+1] * nums[i+1];
        }
        
        // Combine the results
        for (int i = 0; i < n; ++i) {
            result[i] = leftProducts[i] * rightProducts[i];
        }
        
        return result;
    }
};