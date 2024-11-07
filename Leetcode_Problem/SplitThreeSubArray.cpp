/*

Split array in three equal sum subarrays
Difficulty: MediumAccuracy: 52.9%Submissions: 16K+Points: 4
Given an array, arr[], determine if arr can be split into three consecutive parts such that the sum of each part is equal. If possible, return any index pair(i, j) in an array such that sum(arr[0..i]) = sum(arr[i+1..j]) = sum(arr[j+1..n-1]), otherwise return an array {-1,-1}.

Note: Since multiple answers are possible, return any of them. The driver code will print true if it is correct otherwise, it will print false.

Examples :

Input:  arr[] = [1, 3, 4, 0, 4]
Output: true
Explanation: [1, 2] is valid pair as sum of subarray arr[0..1] is equal to sum of subarray arr[2..3] and also to sum of subarray arr[4..4]. The sum is 4, so driver code prints true.
Input: arr[] = [2, 3, 4]
Output: false
Explanation: No three subarrays exist which have equal sum.
Input: arr[] = [0, 1, 1]
Output: false
Constraints:
3 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106

*/
class Solution {
public:
    vector<int> findSplit(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return {-1, -1};
        
        // Calculate total sum of the array
        int total_sum = 0;
        for (int num : arr) total_sum += num;
        
        // If total sum is not divisible by 3, we cannot split into three equal parts
        if (total_sum % 3 != 0) return {-1, -1};
        
        int target_sum = total_sum / 3;
        int current_sum = 0;
        int count = 0;
        vector<int> indices(2, -1);
        
        for (int i = 0; i < n; ++i) {
            current_sum += arr[i];
            
            // Check if current sum matches the target sum
            if (current_sum == target_sum) {
                if (count == 0) {
                    // First split point
                    indices[0] = i;
                    ++count;
                } else if (count == 1) {
                    // Second split point
                    indices[1] = i;
                    ++count;
                    break; // Found both splits, no need to continue
                }
                current_sum = 0; // Reset for the next segment
            }
        }
        
        // If we found both splits, return indices, otherwise {-1, -1}
        if (indices[0] != -1 && indices[1] != -1) return indices;
        return {-1, -1};
    }
};