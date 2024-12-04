/*

trings Rotations of Each Other
Difficulty: EasyAccuracy: 43.83%Submissions: 216K+Points: 2
You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

Examples :

Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: After 2 right rotations, s1 will become equal to s2.
Input: s1 = "aab", s2 = "aba"
Output: true
Explanation: After 1 left rotation, s1 will become equal to s2.
Input: s1 = "abcd", s2 = "acbd"
Output: false
Explanation: Strings are not rotations of each other.
Constraints:
1 <= s1.size(), s2.size() <= 105
*/
class Solution {
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Check if the lengths of the strings are the same
        if (s1.size() != s2.size()) return false;

        // Concatenate s1 with itself
        string temp = s1 + s1;

        // Check if s2 is a substring of the concatenated string
        return (temp.find(s2) != string::npos);
    }
};
