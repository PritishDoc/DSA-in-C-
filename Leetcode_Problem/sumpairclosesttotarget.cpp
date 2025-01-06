/*
Sum Pair closest to target
Difficulty: EasyAccuracy: 44.75%Submissions: 46K+Points: 2
Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a<=b whose sum is closest to target.
Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.

Examples:

Input: arr[] = [10, 30, 20, 5], target = 25
Output: [5, 20]
Explanation: As 5 + 20 = 25 is closest to 25.
Input: arr[] = [5, 2, 7, 1, 4], target = 10
Output: [2, 7]
Explanation: As (4, 7) and (2, 7) both are closest to 10, but absolute difference of (2, 7) is 5 and (4, 7) is 3. Hence, [2, 7] has maximum absolute difference and closest to target. 
Input: arr[] = [10], target = 10
Output: []
Explanation: As the input array has only 1 element, return an empty array.
Constraints:
1 <= arr.size() <= 2*105
0 <= target<= 2*105
0 <= arr[i] <= 105

*/
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        if (arr.size() < 2) return {}; // If the array has less than 2 elements, return empty array.
        
        sort(arr.begin(), arr.end()); // Sort the array.
        int left = 0, right = arr.size() - 1;
        int closestSum = INT_MAX; // Closest sum to the target.
        vector<int> result;
        
        while (left < right) {
            int sum = arr[left] + arr[right];
            
            // Check if this pair is closer to the target
            if (abs(target - sum) < abs(target - closestSum) || 
                (abs(target - sum) == abs(target - closestSum) && (arr[right] - arr[left] > result[1] - result[0]))) {
                closestSum = sum;
                result = {arr[left], arr[right]};
            }
            
            // Move pointers based on the sum
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                // Exact match found
                return {arr[left], arr[right]};
            }
        }
        
        return result;
    }
};
