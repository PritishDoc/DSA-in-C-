/*
Maximum Difference
Difficulty: MediumAccuracy: 33.3%Submissions: 66K+Points: 4
Given an integer array arr of integers, the task is to find the maximum absolute difference between the nearest left smaller element and the nearest right smaller element of every element in array arr. If for any component of the arr, the nearest smaller element doesn't exist then consider it as 0.

Examples :

Input: arr = [2, 1, 8]
Output: 1
Explanation: left smaller array ls = [0, 0, 1], right smaller array rs = [1, 0, 0]. Maximum Diff of abs(ls[i] - rs[i]) = 1
Input: arr = [2, 4, 8, 7, 7, 9, 3]
Output: 4
Explanation: left smaller array ls = [0, 2, 4, 4, 4, 7, 2], right smaller rs = [0, 3, 7, 3, 3, 3, 0]. Maximum Diff of abs(ls[i] - rs[i]) = abs(7 - 3) = 4
Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1 <= arr.size() <= 106
1<= arr[i] <=109
*/
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    int findMaxDiff(vector<int>& arr) {
        int n = arr.size();
        
        // Arrays to store the nearest smaller to left and right
        vector<int> ls(n, 0), rs(n, 0);
        stack<int> st;

        // Find nearest smaller to left
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ls[i] = st.top();
            }
            st.push(arr[i]);
        }

        // Clear the stack for the next computation
        while (!st.empty()) {
            st.pop();
        }

        // Find nearest smaller to right
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                rs[i] = st.top();
            }
            st.push(arr[i]);
        }

        // Compute the maximum absolute difference
        int maxDiff = 0;
        for (int i = 0; i < n; ++i) {
            maxDiff = max(maxDiff, abs(ls[i] - rs[i]));
        }

        return maxDiff;
    }
};
