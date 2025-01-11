/*
Construct K Palindrome Strings
Medium
Hint
Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

 

Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.
Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= 105


*/
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) return false; // Not enough characters for k palindromes
        
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        int oddCount = 0;
        for (auto& entry : freq) {
            if (entry.second % 2 != 0) {
                oddCount++;
            }
        }
        
        // Check if the odd count can fit into k palindromes
        return oddCount <= k;
    }
};
