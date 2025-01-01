/*
Print Anagrams Together
Difficulty: MediumAccuracy: 65.78%Submissions: 82K+Points: 4
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

Note: The final output will be in lexicographic order.

Examples:

Input: arr[] = ["act", "god", "cat", "dog", "tac"]
Output: [["act", "cat", "tac"], ["god", "dog"]]
Explanation: There are 2 groups of anagrams "god", "dog" make group 1. "act", "cat", "tac" make group 2.
Input: arr[] = ["no", "on", "is"]
Output: [["is"], ["no", "on"]]
Explanation: There are 2 groups of anagrams "is" makes group 1. "no", "on" make group 2.
Input: arr[] = ["listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"]
Output: [["abc", "cab", "bac"], ["listen", "silent", "enlist"], ["rat", "tar", "art"]]
Explanation: 
Group 1: "abc", "bac", and "cab" are anagrams.
Group 2: "listen", "silent", and "enlist" are anagrams.
Group 3: "rat", "tar", and "art" are anagrams.
Constraints:
1<= arr.size() <=100
1<= arr[i].size() <=10

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> anagramGroups;

        // Group strings by their sorted version
        for (string str : arr) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramGroups[sortedStr].push_back(str);
        }

        // Collect groups of anagrams into a result vector
        vector<vector<string>> result;
        for (auto& group : anagramGroups) {
            vector<string> anagrams = group.second;
            sort(anagrams.begin(), anagrams.end()); // Sort each group lexicographically
            result.push_back(anagrams);
        }

        // Sort the groups lexicographically based on their first element
        sort(result.begin(), result.end(), [](const vector<string>& a, const vector<string>& b) {
            return a[0] < b[0];
        });

        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<string> arr1 = {"act", "god", "cat", "dog", "tac"};
    vector<string> arr2 = {"no", "on", "is"};
    vector<string> arr3 = {"listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"};

    auto result1 = sol.anagrams(arr1);
    auto result2 = 
