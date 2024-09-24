/*

Smallest window in a string containing all the characters of another string
Difficulty: HardAccuracy: 30.19%Submissions: 157K+Points: 8
Given two strings s and p. Find the smallest window in the string s consisting of all the characters(including duplicates) of the string p.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.
Note : All characters are in Lowercase alphabets. 

Examples:

Input: s = "timetopractice", p = "toc"
Output: toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
Input: s = "zoomlazapzo", p = "oza"
Output: apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(n), n = len(p)

Constraints: 
1 ≤ |s|, |p| ≤ 105
*/
class Solution {
public:
    string smallestWindow(string s, string p) {
        // Frequency map for characters in string p
        vector<int> pFreq(128, 0);  // ASCII characters
        for (char ch : p) {
            pFreq[ch]++;
        }

        int required = p.size();  // Number of characters to match
        int left = 0, right = 0, minLen = INT_MAX, start = 0;
        int windowCount = 0;
        
        vector<int> windowFreq(128, 0);  // Frequency map for the current window

        // Start sliding the window
        while (right < s.size()) {
            char chRight = s[right];
            windowFreq[chRight]++;

            // If the character is needed (exists in pFreq) and we haven't exceeded its required count
            if (pFreq[chRight] > 0 && windowFreq[chRight] <= pFreq[chRight]) {
                windowCount++;
            }

            // When we have all required characters in the current window
            while (windowCount == required) {
                // Update the minimum window length if the current window is smaller
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;  // Update the starting index of the minimum window
                }

                // Try to contract the window by moving the left pointer
                char chLeft = s[left];
                windowFreq[chLeft]--;

                // If we are removing a required character and its count falls below the needed frequency
                if (pFreq[chLeft] > 0 && windowFreq[chLeft] < pFreq[chLeft]) {
                    windowCount--;
                }
                left++;
            }

            // Expand the window by moving the right pointer
            right++;
        }

        // If no valid window was found, return "-1"
        return (minLen == INT_MAX) ? "-1" : s.substr(start, minLen);
    }
};