/*
Longest substring with distinct characters
Difficulty: EasyAccuracy: 31.32%Submissions: 148K+Points: 2
Given a string s, find the length of the longest substring with all distinct characters. 

Examples:

Input: s = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest substring with all distinct characters.
Input: s = "aaa"
Output: 1
Explanation: "a" is the longest substring with all distinct characters.
Input: s = "abcdefabcbb"
Output: 6
Explanation: The longest substring with all distinct characters is "abcdef", which has a length of 6.
Constraints:
1<= s.size()<=3*104
All the characters are in lowercase

*/

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int> lastIndex; // Stores the last index of each character
        int start = 0, maxLength = 0;
        
        for (int end = 0; end < s.size(); ++end) {
            char currentChar = s[end];
            
            // If the character is already in the map and within the current window
            if (lastIndex.find(currentChar) != lastIndex.end() && lastIndex[currentChar] >= start) {
                start = lastIndex[currentChar] + 1; // Move the start pointer
            }
            
            // Update the last index of the current character
            lastIndex[currentChar] = end;
            
            // Update the maximum length
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};
