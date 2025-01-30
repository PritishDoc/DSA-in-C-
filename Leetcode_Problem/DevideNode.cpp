/*
Divide Nodes Into the Maximum Number of Groups
Hint
You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.

You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.

Divide the nodes of the graph into m groups (1-indexed) such that:

Each node in the graph belongs to exactly one group.
For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.

 

Example 1:


Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
Output: 4
Explanation: As shown in the image we:
- Add node 5 to the first group.
- Add node 1 to the second group.
- Add nodes 2 and 4 to the third group.
- Add nodes 3 and 6 to the fourth group.
We can see that every edge is satisfied.
It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.
Example 2:

Input: n = 3, edges = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: If we add node 1 to the first group, node 2 to the second group, and node 3 to the third group to satisfy the first two edges, we can see that the third edge will not be satisfied.
It can be shown that no grouping is possible.
 

Constraints:

1 <= n <= 500
1 <= edges.length <= 104
edges[i].length == 2
1 <= ai, bi <= n
ai != bi
There is at most one edge between any pair of vertices.

*/
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        
        // Build adjacency list
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> component(n + 1, -1);
        vector<vector<int>> components;
        int compIdx = 0;

        // Step 1: Find connected components & check if bipartite
        for (int i = 1; i <= n; i++) {
            if (component[i] == -1) {
                queue<int> q;
                q.push(i);
                component[i] = compIdx;
                vector<int> nodes;
                nodes.push_back(i);
                bool isBipartite = true;
                unordered_map<int, int> color;
                color[i] = 0;
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (int neighbor : graph[node]) {
                        if (component[neighbor] == -1) {
                            component[neighbor] = compIdx;
                            color[neighbor] = 1 - color[node];  // Alternate colors
                            q.push(neighbor);
                            nodes.push_back(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return -1; // Not bipartite
                        }
                    }
                }
                components.push_back(nodes);
                compIdx++;
            }
        }

        // Step 2: Find the max depth of each component
        int result = 0;
        for (auto& comp : components) {
            int maxGroups = 0;
            for (int node : comp) {
                maxGroups = max(maxGroups, bfsMaxDepth(graph, node, n));
            }
            result += maxGroups;
        }
        return result;
    }

private:
    int bfsMaxDepth(vector<vector<int>>& graph, int start, int n) {
        queue<int> q;
        vector<int> dist(n + 1, -1);
        q.push(start);
        dist[start] = 0;
        int maxDepth = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            maxDepth = max(maxDepth, dist[node]);
            for (int neighbor : graph[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        return maxDepth + 1;
    }
};
