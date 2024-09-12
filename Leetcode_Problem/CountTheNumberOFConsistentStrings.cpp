/*
Count the Number of Consistent Strings
Easy
Topics
Companies
Hint
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 

Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.
*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Step 1: Convert the allowed string to a set for O(1) lookup.
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        
        // Step 2: Initialize a counter for consistent strings.
        int consistentCount = 0;
        
        // Step 3: Check each word in the words array.
        for (const string& word : words) {
            bool isConsistent = true;
            for (char ch : word) {
                if (allowedSet.find(ch) == allowedSet.end()) {
                    // If a character in the word is not in the allowed set, mark it inconsistent.
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent) {
                ++consistentCount; // Increment the count if the word is consistent.
            }
        }
        
        return consistentCount; // Return the total count of consistent strings.
    }
};
