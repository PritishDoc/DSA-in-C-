/*


Minimum Number of Swaps to Make the String Balanced

Hint
You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.

 

Example 1:

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
Example 2:

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
Example 3:

Input: s = "[]"
Output: 0
Explanation: The string is already balanced.
 

Constraints:

n == s.length
2 <= n <= 106
n is even.
s[i] is either '[' or ']'.
The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.
*/
class Solution {
public:
    int minSwaps(std::string s) {
        int balance = 0; // Tracks the balance between '[' and ']'
        int max_imbalance = 0; // Tracks the maximum imbalance encountered

        // Traverse the string to calculate balance
        for (char c : s) {
            if (c == '[') {
                balance++;  // Opening bracket increases balance
            } else {
                balance--;  // Closing bracket decreases balance
            }
            
            // If balance goes negative, track the imbalance
            if (balance < 0) {
                max_imbalance = std::max(max_imbalance, -balance);
            }
        }
        
        // Number of swaps needed is half the max imbalance (rounded up)
        // Each swap can fix 2 brackets, so divide max imbalance by 2
        return (max_imbalance + 1) / 2;
    }
};