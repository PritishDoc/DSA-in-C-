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
public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        vector<vector<int>> result;
        int n = arr.size();
        
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        // Step 2: Iterate over the array
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && arr[i] == arr[i - 1]) continue;
            
            int target = -arr[i];
            int left = i + 1, right = n - 1;
            
            // Step 3: Two-pointer approach
            while (left < right) {
                int sum = arr[left] + arr[right];
                if (sum == target) {
                    result.push_back({i, left, right});
                    
                    // Skip duplicates for the second and third elements
                    while (left < right && arr[left] == arr[left + 1]) ++left;
                    while (left < right && arr[right] == arr[right - 1]) --right;
                    
                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return result;
    }
};
