/*
Shortest Distance After Road Addition Queries I
Medium
Hint
You are given an integer n and a 2D integer array queries.

There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.

queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.

Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.

 

Example 1:

Input: n = 5, queries = [[2,4],[0,2],[0,4]]

Output: [3,2,1]

Explanation:



After the addition of the road from 2 to 4, the length of the shortest path from 0 to 4 is 3.



After the addition of the road from 0 to 2, the length of the shortest path from 0 to 4 is 2.



After the addition of the road from 0 to 4, the length of the shortest path from 0 to 4 is 1.

Example 2:

Input: n = 4, queries = [[0,3],[0,2]]

Output: [1,1]

Explanation:



After the addition of the road from 0 to 3, the length of the shortest path from 0 to 3 is 1.



After the addition of the road from 0 to 2, the length of the shortest path remains 1.

 

Constraints:

3 <= n <= 500
1 <= queries.length <= 500
queries[i].length == 2
0 <= queries[i][0] < queries[i][1] < n
1 < queries[i][1] - queries[i][0]
There are no repeated roads among the queries.
*/
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Adjacency list representation of the graph
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < n - 1; ++i) {
            graph[i].push_back({i + 1, 1});
        }
        
        vector<int> result;
        
        // Function to find shortest path using Dijkstra's algorithm
        auto dijkstra = [&](int start, int end) {
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            
            dist[start] = 0;
            pq.push({0, start});
            
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                
                if (d > dist[u]) continue; // Skip outdated paths
                
                for (auto [v, w] : graph[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            
            return dist[end];
        };
        
        // Process each query
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            graph[u].push_back({v, 1}); // Add the new road
            result.push_back(dijkstra(0, n - 1)); // Compute shortest path
        }
        
        return result;
    }
};
