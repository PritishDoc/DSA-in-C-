/*
Count Ways To Build Good Strings

Hint
Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

 

Example 1:

Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation: 
One possible valid good string is "011". 
It can be constructed as follows: "" -> "0" -> "01" -> "011". 
All binary strings from "000" to "111" are good strings in this example.
Example 2:

Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".
 

Constraints:

1 <= low <= high <= 105
1 <= zero, one <= low

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        
        // dp[i] will store the number of good strings of length i.
        vector<int> dp(high + 1, 0);
        dp[0] = 1; // Base case: There's one way to make an empty string.

        int result = 0;

        // Compute the number of good strings for each length from 1 to high.
        for (int length = 1; length <= high; ++length) {
            // If we append `zero` 0's to a string of length `length - zero`
            if (length >= zero) {
                dp[length] = (dp[length] + dp[length - zero]) % MOD;
            }
            // If we append `one` 1's to a string of length `length - one`
            if (length >= one) {
                dp[length] = (dp[length] + dp[length - one]) % MOD;
            }

            // If the current length is within the range [low, high], add to the result.
            if (length >= low) {
                result = (result + dp[length]) % MOD;
            }
        }

        return result;
    }
};

// Driver code to test the function
int main() {
    Solution solution;
    int low = 3, high = 3, zero = 1, one = 1;
    cout << solution.countGoodStrings(low, high, zero, one) << endl; // Output: 8

    low = 2, high = 3, zero = 1, one = 2;
    cout << solution.countGoodStrings(low, high, zero, one) << endl; // Output: 5

    return 0;
}
