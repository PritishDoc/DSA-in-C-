/*
Nearest multiple of 10
Difficulty: EasyAccuracy: 19.32%Submissions: 72K+Points: 2
A string str is given to represent a positive number. The task is to round str to the nearest multiple of 10.  If you have two multiples equally apart from str, choose the smallest element among them.

Examples:

Input: str = 29 
Output: 30
Explanation: Close multiples are 20 and 30, and 30 is the nearest to 29. 
Input: str = 15
Output: 10
Explanation: 10 and 20 are equally distant multiples from 20. The smallest of the two is 10.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= str.size()<= 105

*/
class Solution {
public:
    string roundToNearest(string str) {
        int n = str.size();
        int lastDigit = str[n - 1] - '0';  // Extract the last digit

        // If the last digit is less than or equal to 5, round down
        if (lastDigit <= 5) {
            str[n - 1] = '0';  // Set last digit to '0'
        } else {
            // If the last digit is greater than 5, round up
            int i = n - 1;
            str[i] = '0';  // Set the last digit to '0'

            // Carry over the rounding process from right to left
            i--;
            while (i >= 0 && str[i] == '9') {
                str[i] = '0';  // Set current digit to 0 and carry the 1 to the left
                i--;
            }
            if (i >= 0) {
                str[i]++;  // Increase the current digit if it's not already at 9
            } else {
                // If all digits were '9', prepend '1' to the number
                str = '1' + str;
            }
        }

        return str;
    }
};
