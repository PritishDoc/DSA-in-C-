/**
 

 
Code


Testcase
Test Result
Test Result
440. K-th Smallest in Lexicographical Order
Hard
Topics
Companies
Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 

Example 1:

Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
Example 2:

Input: n = 1, k = 1
Output: 1
 
 */

class Solution {
public:
    // Helper function to count how many numbers lie between current and next in the lexicographical order
    long long countNumbers(long long prefix, long long n) {
        long long count = 0;
        long long curr = prefix;
        long long next = prefix + 1;
        
        while (curr <= n) {
            count += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return count;
    }
    
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;  // Since we start from 1
        
        while (k > 0) {
            long long count = countNumbers(curr, n);
            
            if (count <= k) {
                // Skip the current prefix
                k -= count;
                curr++;  // Move to the next prefix
            } else {
                // Explore this prefix further
                curr *= 10;  // Move down to the next level (e.g., from 1 to 10)
                k--;  // Account for the current number
            }
        }
        
        return curr;
    }
};