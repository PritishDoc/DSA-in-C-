/*

Permutation in String
Medium
Topics

Hint
Given two strings s1 and s2, return true if s2 contains a 
permutation
 of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        vector<int> s1_freq(26, 0), window_freq(26, 0);
        
        // Calculate the frequency of characters in s1
        for (char c : s1) {
            s1_freq[c - 'a']++;
        }
        
        // Initial window frequency for the first window in s2
        for (int i = 0; i < s1.size(); i++) {
            window_freq[s2[i] - 'a']++;
        }
        
        // Sliding window comparison
        for (int i = s1.size(); i < s2.size(); i++) {
            if (s1_freq == window_freq) {
                return true; // Found a matching permutation
            }
            
            // Slide the window: include s2[i], exclude s2[i - s1.size()]
            window_freq[s2[i] - 'a']++;
            window_freq[s2[i - s1.size()] - 'a']--;
        }
        
        // Check the last window
        return s1_freq == window_freq;
    }
};
