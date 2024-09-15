/*

Find the Longest Substring Containing Vowels in Even Counts

Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

 

Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
 

Constraints:

1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.
*/
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> maskPos;
        maskPos[0] = -1;  // Initial state: all vowels occur an even number of times
        int mask = 0;  // This will be used to track the parity of vowels
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            // Update the mask for the current vowel
            if (ch == 'a') {
                mask ^= 1 << 0;  // Flip the bit for 'a'
            } else if (ch == 'e') {
                mask ^= 1 << 1;  // Flip the bit for 'e'
            } else if (ch == 'i') {
                mask ^= 1 << 2;  // Flip the bit for 'i'
            } else if (ch == 'o') {
                mask ^= 1 << 3;  // Flip the bit for 'o'
            } else if (ch == 'u') {
                mask ^= 1 << 4;  // Flip the bit for 'u'
            }

            // If the current mask has been seen before, calculate the substring length
            if (maskPos.find(mask) != maskPos.end()) {
                maxLength = max(maxLength, i - maskPos[mask]);
            } else {
                // Otherwise, store the position of this mask
                maskPos[mask] = i;
            }
        }

        return maxLength;
    }
};