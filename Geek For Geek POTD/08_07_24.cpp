/*
Remove Duplicates
Difficulty: EasyAccuracy: 52.35%Submissions: 120K+Points: 2
Given a string str without spaces, the task is to remove all duplicate characters from it, keeping only the first occurrence.

Note: The original order of characters must be kept the same. 

Examples :

Input: str = "zvvo"
Output: "zvo"
Explanation: Only keep the first occurrence
Input: str = "gfg"
Output: "gf"
Explanation: Only keep the first occurrence
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
*/
class Solution {
public:
    string removeDups(string str) {
        unordered_set<char> seen;
        string result;
        
        for (char c : str) {
            if (seen.find(c) == seen.end()) {
                seen.insert(c);
                result += c;
            }
        }
        
        return result;
    }
};
