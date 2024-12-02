/*
Search Pattern (KMP-Algorithm)
Difficulty: MediumAccuracy: 45.04%Submissions: 82K+Points: 4
Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 
Note: Return an empty list in case of no occurrences of pattern.

Examples :

Input: txt = "abcab", pat = "ab"
Output: [0, 3]
Explanation: The string "ab" occurs twice in txt, one starts at index 0 and the other at index 3. 
Input: txt = "abesdu", pat = "edu"
Output: []
Explanation: There's no substring "edu" present in txt.
Input: txt = "aabaacaadaabaaba", pat = "aaba"
Output: [0, 9, 12]
Explanation:

Constraints:
1 ≤ txt.size() ≤ 106
1 ≤ pat.size() < txt.size()
Both the strings consist of lowercase English alphabets.
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> search(string& pat, string& txt) {
        int m = pat.size();
        int n = txt.size();
        
        // Compute the LPS array
        vector<int> lps(m, 0);
        computeLPSArray(pat, m, lps);
        
        vector<int> result;
        int i = 0; // index for txt
        int j = 0; // index for pat
        
        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            
            if (j == m) {
                // Found a match, store the starting index
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && pat[j] != txt[i]) {
                // Mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return result;
    }
    
private:
    void computeLPSArray(string& pat, int m, vector<int>& lps) {
        int len = 0; // Length of previous longest prefix suffix
        lps[0] = 0;  // LPS[0] is always 0
        int i = 1;   // Start from the second character
        
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
};
