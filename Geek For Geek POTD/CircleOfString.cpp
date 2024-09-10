/*
Circle of strings
Difficulty: HardAccuracy: 15.56%Submissions: 74K+Points: 8
Given an array arr of lowercase strings, determine if the strings can be chained together to form a circle.
A string X can be chained together with another string Y if the last character of X is the same as the first character of Y. If every string of the array can be chained with exactly two strings of the array(one with the first character and the second with the last character of the string), it will form a circle.

For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"

Examples

Input: arr[] = ["abc", "bcd", "cdf"]
Output: 0
Explaination: These strings can't form a circle because no string has 'd'at the starting index.
Input: arr[] = ["ab" , "bc", "cd", "da"]
Output: 1
Explaination: These strings can form a circle of strings.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints: 
1 ≤ length of strings ≤ 20
*/

#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u, adj, visited);
            }
        }
    }
    
    // Function to check if all characters with non-zero degree are in the same SCC
    bool isStronglyConnected(vector<vector<int>>& adj, vector<vector<int>>& revAdj, vector<bool>& visited, int start) {
        // First DFS on original graph
        dfs(start, adj, visited);
        
        // Check if all vertices with non-zero out-degree are visited
        for (int i = 0; i < 26; ++i) {
            if (!visited[i] && (!adj[i].empty() || !revAdj[i].empty())) {
                return false;
            }
        }
        
        // Reset visited array for reverse DFS
        fill(visited.begin(), visited.end(), false);
        
        // Second DFS on reversed graph
        dfs(start, revAdj, visited);
        
        // Check if all vertices with non-zero in-degree are visited
        for (int i = 0; i < 26; ++i) {
            if (!visited[i] && (!adj[i].empty() || !revAdj[i].empty())) {
                return false;
            }
        }
        
        return true;
    }
    
    int isCircle(vector<string>& arr) {
        vector<int> inDegree(26, 0), outDegree(26, 0);
        vector<vector<int>> adj(26), revAdj(26); // Adjacency list and reverse adjacency list
        
        // Build graph
        for (const string& s : arr) {
            int u = s[0] - 'a'; // First character
            int v = s.back() - 'a'; // Last character
            adj[u].push_back(v);
            revAdj[v].push_back(u);
            outDegree[u]++;
            inDegree[v]++;
        }
        
        // Check if in-degree and out-degree of every vertex are the same
        for (int i = 0; i < 26; ++i) {
            if (inDegree[i] != outDegree[i]) {
                return 0;
            }
        }
        
        // Find a vertex with non-zero degree to start DFS
        int start = -1;
        for (int i = 0; i < 26; ++i) {
            if (!adj[i].empty()) {
                start = i;
                break;
            }
        }
        
        // If no edges exist, the strings can't form a circle
        if (start == -1) {
            return 0;
        }
        
        // Check if all vertices with non-zero degree are in the same SCC
        vector<bool> visited(26, false);
        if (!isStronglyConnected(adj, revAdj, visited, start)) {
            return 0;
        }
        
        return 1;
    }
};
