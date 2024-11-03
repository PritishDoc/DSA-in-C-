/*

Rotate String
Easy
Topics

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if the lengths of s and goal are the same
        if (s.length() != goal.length()) {
            return false;
        }

        // Concatenate s with itself and check if goal is a substring
        string doubled = s + s;
        return doubled.find(goal) != string::npos;
    }
};
