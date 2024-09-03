/*
Sum of Digits of String After Convert
Easy
Topics
Companies
Hint
You are given a string s consisting of lowercase English letters, and an integer k.

First, convert s into an integer by replacing each letter with its position in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). Then, transform the integer by replacing it with the sum of its digits. Repeat the transform operation k times in total.

For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
Transform #2: 17 ➝ 1 + 7 ➝ 8
Return the resulting integer after performing the operations described above.

 

Example 1:

Input: s = "iiii", k = 1
Output: 36
Explanation: The operations are as follows:
- Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
Thus the resulting integer is 36.
Example 2:

Input: s = "leetcode", k = 2
Output: 6
Explanation: The operations are as follows:
- Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
- Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
- Transform #2: 33 ➝ 3 + 3 ➝ 6
Thus the resulting integer is 6.
Example 3:

Input: s = "zbax", k = 2
Output: 8
 


*/
class Solution {
public:
    int getLucky(string s, int k) {
        string numericString = "";
        
        // Convert the string into the corresponding numeric string
        for (char c : s) {
            int value = c - 'a' + 1;  // Convert char to its alphabet position
            numericString += to_string(value);  // Append to numeric string
        }
        
        // Helper function to calculate the sum of digits of a number represented as a string
        auto sumOfDigits = [](string num) {
            int sum = 0;
            for (char digit : num) {
                sum += digit - '0';  // Convert char digit to integer and sum up
            }
            return sum;
        };
        
        // Perform the transformation k times
        for (int i = 0; i < k; ++i) {
            int sum = sumOfDigits(numericString);
            numericString = to_string(sum);  // Update numericString with the new sum as string
        }
        
        // Return the final integer after k transformations
        return stoi(numericString);
    }
};
