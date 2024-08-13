/*
Square root of a number
Difficulty: EasyAccuracy: 54.03%Submissions: 244K+Points: 2
Given an integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number

Examples:

Input: n = 5
Output: 2
Explanation: Since, 5 is not a perfect square, floor of square_root of 5 is 2.
Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.
Expected Time Complexity: O(logn)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 107
*/
#include <iostream>

class Solution {
public:
    long long int floorSqrt(long long int n) {
        if (n == 0 || n == 1)
            return n;

        long long int start = 1, end = n, ans = 0;
        
        while (start <= end) {
            long long int mid = (start + end) / 2;
            
            // If mid*mid is equal to n, return mid
            if (mid * mid == n)
                return mid;
            
            // If mid*mid is less than n, move to the right half
            if (mid * mid < n) {
                start = mid + 1;
                ans = mid; // Keep track of the floor of sqrt(n)
            } 
            // If mid*mid is greater than n, move to the left half
            else {
                end = mid - 1;
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;

    long long int n1 = 5;
    std::cout << "The floor square root of " << n1 << " is " << sol.floorSqrt(n1) << std::endl; // Output: 2

    long long int n2 = 4;
    std::cout << "The floor square root of " << n2 << " is " << sol.floorSqrt(n2) << std::endl; // Output: 2

    long long int n3 = 10;
    std::cout << "The floor square root of " << n3 << " is " << sol.floorSqrt(n3) << std::endl; // Output: 3

    return 0;
}
