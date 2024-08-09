/*
Maximize Array Value After Rearrangement
Difficulty: EasyAccuracy: 18.93%Submissions: 253K+Points: 2
Given an array arr of n integers. Your task is to write a program to find the maximum value of ∑arr[i]*i, where i = 0, 1, 2,., n-1. You are allowed to rearrange the elements of the array.

Note: Since the output could be large, print the answer modulo 109+7.

Examples :

Input : arr[] = [5, 3, 2, 4, 1]
Output : 40
Explanation: If we arrange the array as 1 2 3 4 5 then we can see that the minimum index will multiply with minimum number and maximum index will multiply with maximum number. So, 1*0 + 2*1 + 3*2 + 4*3 + 5*4 = 0+2+6+12+20 = 40 mod(109+7) = 40

Input : arr[] = [1, 2, 3]
Output : 8
Expected Time Complexity: O(nlog(n))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size ≤ 105
1 ≤ arri ≤ 105


*/

class Solution {
public:
    int Maximize(std::vector<int> &arr) {
        // Define the modulo constant
        const int MOD = 1e9 + 7;

        // Sort the array in non-decreasing order
        std::sort(arr.begin(), arr.end());

        // Initialize the result variable
        long long result = 0;

        // Calculate the sum of arr[i] * i
        for (int i = 0; i < arr.size(); ++i) {
            result = (result + static_cast<long long>(arr[i]) * i) % MOD;
        }

        // Return the result
        return result;
    }
};