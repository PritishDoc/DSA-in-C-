/*

Subarray range with given sum
Difficulty: MediumAccuracy: 42.21%Submissions: 45K+Points: 4
Given an unsorted array of integers arr[], and a target tar, determine the number of subarrays whose elements sum up to the target value.

Examples:

Input: arr[] = [10, 2, -2, -20, 10] , tar = -10
Output: 3
Explanation: Subarrays with sum -10 are: [10, 2, -2, -20], [2, -2, -20, 10] and [-20, 10].
Input: arr[] = [1, 4, 20, 3, 10, 5] , tar = 33
Output: 1
Explanation: Subarray with sum 33 is: [20,3,10].
Expected Time Complexity: O(n)
Expected Auxilary Space: O(n)

Constraints:
1 <= arr.size() <= 106
-105 <= arr[i] <= 105
-105 <= tar <= 105
*/
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Using long long to prevent overflow for large prefix sums
        unordered_map<long long, int> prefixSumCounts;
        prefixSumCounts[0] = 1; // Base case: prefix sum of 0 occurs once
        long long current_sum = 0;
        long long count = 0;
        
        for(auto num : arr){
            current_sum += num;
            
            // Check if (current_sum - tar) exists in the map
            if(prefixSumCounts.find(current_sum - (long long)tar) != prefixSumCounts.end()){
                count += prefixSumCounts[current_sum - tar];
            }
            
            // Increment the count of current_sum in the map
            prefixSumCounts[current_sum]++;
        }
        
        // Since the count can be large, but the function expects an int,
        // we cast it to int. If counts can exceed int limits, consider changing the return type.
        return (int)count;
    }
};

// Below is a simple main function to test the above solution.
// You can remove or comment out this part when submitting your code.

int main(){
    Solution sol;
    // Test Case 1
    vector<int> arr1 = {10, 2, -2, -20, 10};
    int tar1 = -10;
    cout << "Output: " << sol.subArraySum(arr1, tar1) << endl; // Expected: 3

    // Test Case 2
    vector<int> arr2 = {1, 4, 20, 3, 10, 5};
    int tar2 = 33;
    cout << "Output: " << sol.subArraySum(arr2, tar2) << endl; // Expected: 1

    // Additional Test Case
    vector<int> arr3 = {1, -1, 0};
    int tar3 = 0;
    cout << "Output: " << sol.subArraySum(arr3, tar3) << endl; // Expected: 3

    return 0;
}