/*

Alien Dictionary
Difficulty: HardAccuracy: 47.81%Submissions: 120K+Points: 8
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

Examples :

Input:  n = 5, k = 4, dict = {"baa","abcd","abca","cab","cad"}
Output: 1
Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Input: n = 3, k = 3, dict = {"caa","aaa","aab"}
Output: 1
Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before "aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
Expected Time Complexity: O(n * |s| + k)
Expected Auxillary Space: O(k)

Constraints:
1 ≤ n≤ 104
1 ≤ k ≤ 26
1 ≤ Length of words ≤ 50
*/
#include <vector>
#include <queue>
#include <string>

class Solution {
public:
    string findOrder(string dict[], int n, int k) {
        // Step 1: Create a graph
        vector<vector<int>> graph(k, vector<int>());
        vector<int> indegree(k, 0);
        
        // Step 2: Build the graph
        for (int i = 0; i < n - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];
            for (int j = 0; j < min(word1.length(), word2.length()); j++) {
                if (word1[j] != word2[j]) {
                    int u = word1[j] - 'a';
                    int v = word2[j] - 'a';
                    graph[u].push_back(v);
                    indegree[v]++;
                    break;
                }
            }
        }
        
        // Step 3: Perform topological sort
        queue<int> q;
        string result = "";
        
        // Start with nodes that have zero indegree
        for (int i = 0; i < k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result += (char)(u + 'a');
            
            for (int v : graph[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // If result length is less than k, then there's a cycle, and topological sort isn't possible
        if (result.length() < k) {
            return "";
        }
        
        return result;
    }
};
