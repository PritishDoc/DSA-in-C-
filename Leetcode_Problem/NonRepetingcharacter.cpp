/*
Non Repeating Character
Difficulty: EasyAccuracy: 40.43%Submissions: 246K+Points: 2
Given a string s consisting of lowercase Latin Letters. Return the first non-repeating character in s. If there is no non-repeating character, return '$'.
Note: When you return '$' driver code will output -1.

Examples:

Input: s = "geeksforgeeks"
Output: 'f'
Explanation: In the given string, 'f' is the first character in the string which does not repeat.
Input: s = "racecar"
Output: 'e'
Explanation: In the given string, 'e' is the only character in the string which does not repeat.
Input: s = "aabbccc"
Output: -1
Explanation: All the characters in the given string are repeating.
Constraints:
1 <= s.size() <= 105


*/

class Solution {
public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        unordered_map<char, int> freq; // To store frequency of characters

        // Count the frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Traverse the string again to find the first character with frequency 1
        for (char c : s) {
            if (freq[c] == 1) {
                return c;
            }
        }

        return '$'; // If no non-repeating character is found
    }
};