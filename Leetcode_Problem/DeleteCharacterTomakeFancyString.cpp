/*

Delete Characters to Make Fancy String
Easy

Hint
A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

 

Example 1:

Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
Example 3:

Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".
 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
*/
class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 1;  // Start with 1 since we're counting the first character
        
        // Add the first character to the result
        result += s[0];

        // Iterate through the string starting from the second character
        for (int i = 1; i < s.size(); i++) {
            // Check if the current character is the same as the previous one
            if (s[i] == s[i - 1]) {
                count++;  // Increment the count for consecutive characters
            } else {
                count = 1;  // Reset count if characters are different
            }
            
            // Only add the character if it's not part of three or more consecutive characters
            if (count < 3) {
                result += s[i];
            }
        }

        return result;
    }
};