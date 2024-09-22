/*



Longest Prefix Suffix
Difficulty: HardAccuracy: 27.91%Submissions: 126K+Points: 8
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Examples :

Input: str = "abab"
Output: 2
Explanation: "ab" is the longest proper prefix and suffix. 
Input: str = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper prefix and suffix. 
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |str| ≤ 106
str contains lower case English alphabets
*/

class Solution {
public:
    int lps(string str) {
        int n = str.length();
        vector<int> lps(n, 0);  // Create an array to store the lps values
        
        int len = 0;  // Length of the previous longest prefix suffix
        int i = 1;
        
        // Build the lps array
        while (i < n) {
            if (str[i] == str[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // Fall back to the last longest prefix suffix
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // The value of lps[n-1] will give us the length of the longest proper prefix
        // which is also a proper suffix
        return lps[n - 1];
    }
};
