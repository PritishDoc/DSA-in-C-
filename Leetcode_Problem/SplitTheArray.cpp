/*
Split the Array
Difficulty: EasyAccuracy: 54.99%Submissions: 12K+Points: 2
Given an array arr[] of integers, the task is to count the number of ways to split given array elements into two non-empty subsets such that the XOR of elements of each group is equal. Each element should belong to exactly one subset.
Note:

The answer could be very large so print it by doing modulo with 109 + 7. 
Subsets with the same elements but derived from different indices are different.
Examples:

Input : arr[] = [1, 2, 3]
Output : 3
Explanation: {(1),(2, 3)}, {(2),(1, 3)}, {(3),(1, 2)} are three ways with equal XOR value of two groups.
Input : arr[] = [5, 2, 3, 2]
Output : 0
Explanation: No way to split into  two groups whose XOR is equal.
Input : arr[] = [2, 2, 2, 2]
Output : 7
Explanation: There are 7 ways to split the array into two groups with equal XOR, such that there are multiple combinations of {(2), (2,2,2)},{(2,2),(2,2)}.
Constraints:
1<=arr.size()<=106
1<=arr[i]<=106
*/

class Solution {
public:
    int countgroup(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        
        // Step 1: Calculate the XOR of the entire array
        int XOR_all = 0;
        for (int num : arr) {
            XOR_all ^= num;
        }
        
        // Step 2: If XOR of all elements is not 0, return 0
        if (XOR_all != 0) {
            return 0;
        }
        
        // Step 3: Count how many times XOR reduces to 0
        // We can partition the array in (2^(n-1)) - 1 ways
        // Why n-1? Because each element can either go into one subset or another, except the last element which automatically goes to a subset.
        // Subtract 1 to avoid the case where all elements are in the same subset
        
        long long total_ways = 1;
        for (int i = 0; i < n - 1; ++i) {
            total_ways = (total_ways * 2) % MOD;
        }
        
        return total_ways - 1;
    }
};