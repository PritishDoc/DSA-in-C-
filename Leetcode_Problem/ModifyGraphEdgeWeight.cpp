/*
Modify Graph Edge Weights
Hard
Topics
Companies
Hint
You are given an undirected weighted connected graph containing n nodes labeled from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.

Some edges have a weight of -1 (wi = -1), while others have a positive weight (wi > 0).

Your task is to modify all edges with a weight of -1 by assigning them positive integer values in the range [1, 2 * 109] so that the shortest distance between the nodes source and destination becomes equal to an integer target. If there are multiple modifications that make the shortest distance between source and destination equal to target, any of them will be considered correct.

Return an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from source to destination equal to target, or an empty array if it's impossible.

Note: You are not allowed to modify the weights of edges with initial positive weights.

 

Example 1:



Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
Explanation: The graph above shows a possible modification to the edges, making the distance from 0 to 1 equal to 5.
Example 2:



Input: n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
Output: []
Explanation: The graph above contains the initial edges. It is not possible to make the distance from 0 to 2 equal to 6 by modifying the edge with weight -1. So, an empty array is returned.
Example 3:



Input: n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
Output: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
Explanation: The graph above shows a modified graph having the shortest distance from 0 to 2 as 6.
*/
class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            graph[u].emplace_back(v, i);
            graph[v].emplace_back(u, i);
        }
        
        auto dijkstra = [&](int start, vector<vector<int>>& edges) {
            vector<long long> dist(n, LLONG_MAX);
            dist[start] = 0;
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            pq.emplace(0, start);
            
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;
                
                for (auto [v, idx] : graph[u]) {
                    int w = edges[idx][2];
                    if (w == -1) w = 1;  // Treat -1 as 1 initially
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pq.emplace(dist[v], v);
                    }
                }
            }
            return dist[destination];
        };
        
        // Initial shortest path considering -1 edges as weight 1
        long long initialDist = dijkstra(source, edges);
        if (initialDist < target) {
            // Try to increase the weight of one or more -1 edges
            for (auto& edge : edges) {
                if (edge[2] == -1) edge[2] = 1;
            }
            if (dijkstra(source, edges) > target) return {};
            
            // Binary search to find the appropriate weight
            for (int i = 0; i < edges.size(); ++i) {
                if (edges[i][2] == 1) {
                    edges[i][2] = 1;  // reset
                    int lo = 1, hi = 2e9, optimal = -1;
                    while (lo <= hi) {
                        int mid = lo + (hi - lo) / 2;
                        edges[i][2] = mid;
                        if (dijkstra(source, edges) >= target) {
                            optimal = mid;
                            hi = mid - 1;
                        } else {
                            lo = mid + 1;
                        }
                    }
                    if (optimal != -1) edges[i][2] = optimal;
                    if (dijkstra(source, edges) == target) return edges;
                }
            }
        } else if (initialDist == target) {
            // If the initial distance is already equal to the target
            for (auto& edge : edges) {
                if (edge[2] == -1) edge[2] = 1;
            }
            return edges;
        }
        
        // If no valid configuration is found
        return {};
    }
};