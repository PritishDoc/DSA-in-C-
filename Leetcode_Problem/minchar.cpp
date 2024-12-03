/*
Min Chars to Add for Palindrome
Difficulty: HardAccuracy: 46.79%Submissions: 60K+Points: 8
Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Note: A palindrome string is a sequence of characters that reads the same forward and backward.

Examples:

Input: s = "abc"
Output: 2
Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"
Input: s = "aacecaaaa"
Output: 2
Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"
Constraints:
1 <= s.size() <= 106

*/
class Solution {
public:
    int minChar(string& s) {
        string rev_s = s; // Reverse the string
        reverse(rev_s.begin(), rev_s.end());

        // Create a new string with separator to avoid overlap
        string combined = s + "#" + rev_s;

        // Apply KMP algorithm to find the longest prefix-suffix match
        vector<int> lps(combined.size(), 0);
        
        // Build the prefix function for the combined string
        for (int i = 1; i < combined.size(); ++i) {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            lps[i] = j;
        }

        // The last value in lps array gives the length of the longest palindromic suffix
        int longest_palindromic_suffix = lps[combined.size() - 1];

        // To make the string a palindrome, we need to add characters before the string
        return s.size() - longest_palindromic_suffix;
    }
};