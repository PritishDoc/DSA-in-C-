/*
Longest Common Prefix of Strings
Difficulty: EasyAccuracy: 29.52%Submissions: 271K+Points: 2
Given an array of strings arr. Return the longest common prefix among all strings present in the array. If there's no prefix common in all the strings, return "-1".

Examples :

Input: arr[] = ["geeksforgeeks", "geeks", "geek", "geezer"]
Output: gee
Explanation: "gee" is the longest common prefix in all the given strings.
Input: arr[] = ["hello", "world"]
Output: -1
Explanation: There's no common prefix in the given strings.
Expected Time Complexity: O(n*min(|arri|))
Expected Space Complexity: O(min(|arri|))

Constraints:
1 ≤ |arr| ≤ 103
1 ≤ |arr[i]| ≤ 103
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        if (arr.empty()) return "-1";
        
        // Start with the first string as the initial prefix
        string prefix = arr[0];
        
        // Compare the prefix with each string in the array
        for (int i = 1; i < arr.size(); ++i) {
            while (arr[i].find(prefix) != 0) {
                // Trim the last character from the prefix
                prefix = prefix.substr(0, prefix.size() - 1);
                // If the prefix becomes empty, return -1
                if (prefix.empty()) return "-1";
            }
        }
        
        return prefix;
    }
};
