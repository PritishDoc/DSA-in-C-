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

        // Use KMP algorithm to check if s2 is a substring of temp
        return kmpSearch(temp, s2);
    }

private:
    // Helper function to create the LPS array for KMP
    vector<int> computeLPS(string &pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0, i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    // KMP search function
    bool kmpSearch(string &text, string &pattern) {
        int n = text.size();
        int m = pattern.size();
        vector<int> lps = computeLPS(pattern);

        int i = 0, j = 0; // Pointers for text and pattern
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return true; // Found pattern in text
            } else if (i < n && text[i] != pattern[j]) {
                if (j > 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false; // Pattern not found
    }
};
