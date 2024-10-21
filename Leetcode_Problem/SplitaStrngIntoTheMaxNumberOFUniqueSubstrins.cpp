/*

 Split a String Into the Max Number of Unique Substrings
Medium
Topics
Companies
Hint
Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
Example 2:

Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba'].
Example 3:

Input: s = "aa"
Output: 1
Explanation: It is impossible to split the string any further.
 

Constraints:

1 <= s.length <= 16
*/

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> uniqueSubstrings;
        return backtrack(s, 0, uniqueSubstrings);
    }
    
    int backtrack(const string& s, int start, unordered_set<string>& uniqueSubstrings) {
        if (start == s.length()) {
            // Base case: If we have reached the end of the string, return 0 splits remaining
            return 0;
        }
        
        int maxSplits = 0;
        string currentSubstring = "";
        
        // Try all possible substrings starting from 'start' to the end of the string
        for (int i = start; i < s.length(); ++i) {
            currentSubstring += s[i];
            
            // If the current substring is unique, we attempt to split further
            if (uniqueSubstrings.find(currentSubstring) == uniqueSubstrings.end()) {
                uniqueSubstrings.insert(currentSubstring);
                
                // Recursively find the number of splits for the remaining string
                int splits = 1 + backtrack(s, i + 1, uniqueSubstrings);
                maxSplits = max(maxSplits, splits);
                
                // Backtrack: remove the current substring and try another split
                uniqueSubstrings.erase(currentSubstring);
            }
        }
        
        return maxSplits;
    }
};