/*

 Take K of Each Character From Left and Right
Medium
Topics
Companies
Hint
You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.

Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

 

Example 1:

Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation: 
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.
Example 2:

Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.
 

Constraints:

1 <= s.length <= 105
s consists of only the letters 'a', 'b', and 'c'.
0 <= k <= s.length
*/

class Solution {
public:
    int takeCharacters(string s, int k) {
        // Step 1: Count total occurrences of 'a', 'b', and 'c'
        unordered_map<char, int> totalCount;
        for (char c : s) {
            totalCount[c]++;
        }

        // Step 2: Check if it is possible to take at least k of each character
        if (totalCount['a'] < k || totalCount['b'] < k || totalCount['c'] < k) {
            return -1;
        }

        // Step 3: Use sliding window to find the longest subarray
        int n = s.size();
        unordered_map<char, int> windowCount;
        int maxLength = 0, left = 0;

        for (int right = 0; right < n; ++right) {
            windowCount[s[right]]++;

            // Shrink the window if the condition is violated
            while (totalCount['a'] - windowCount['a'] < k ||
                   totalCount['b'] - windowCount['b'] < k ||
                   totalCount['c'] - windowCount['c'] < k) {
                windowCount[s[left]]--;
                left++;
            }

            // Update the maximum length of the valid window
            maxLength = max(maxLength, right - left + 1);
        }

        // Step 4: Calculate the minimum minutes required
        return n - maxLength;
    }
};