/*
 Shortest Palindrome
Hard
Topics
Companies
You are given a string s. You can convert s to a 
palindrome
 by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 

Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        // Create a new string that appends reverse of s to s, separated by '#'
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string new_s = s + "#" + rev_s;

        // KMP table
        vector<int> lps(new_s.size(), 0);  // Longest Prefix Suffix (LPS) table

        // KMP preprocessing: Building the LPS array
        for (int i = 1; i < new_s.size(); i++) {
            int j = lps[i - 1];  // j points to the end of the longest prefix suffix
            while (j > 0 && new_s[i] != new_s[j]) {
                j = lps[j - 1];  // If mismatch, fall back to the previous LPS value
            }
            if (new_s[i] == new_s[j]) {
                j++;  // If match, increment j
            }
            lps[i] = j;  // Update LPS table
        }

        // The length of the longest palindrome prefix is stored in lps.back()
        int palindrome_len = lps.back();
        
        // Add the reverse of the remaining suffix (after the palindrome prefix) in front of s
        return rev_s.substr(0, s.size() - palindrome_len) + s;
    }
};
