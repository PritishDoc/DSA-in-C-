/*

Minimum Cost Path
Difficulty: HardAccuracy: 26.99%Submissions: 91K+Points: 8
Given a square grid of size N, each cell of which contains an integer cost that represents a cost to traverse through that cell, we need to find a path from the top left cell to the bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).  

Examples :

Input: grid = {{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}}
Output: 43
Explanation: The grid is-
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.
Input: grid = {{4,4},{3,7}}
Output: 14
Explanation: The grid is-
4 4
3 7
The minimum cost is- 4 + 3 + 7 = 14.
Expected Time Complexity: O(n2*log(n))
Expected Auxiliary Space: O(n2) 
 Constraints:
1 ≤ n ≤ 500
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the minimum cost to reach the bottom-right cell from the top-left cell.
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        // Priority queue to store the cells to be processed (min-heap).
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        // Direction arrays for moving in four possible directions.
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        // Start with the top-left cell.
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int cost = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            
            // If we reach the bottom-right corner, return the cost.
            if (x == n-1 && y == n-1) return cost;
            
            // Explore the neighbors.
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // Check if the new position is within bounds.
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    int new_cost = cost + grid[nx][ny];
                    if (new_cost < dist[nx][ny]) {
                        dist[nx][ny] = new_cost;
                        pq.push({new_cost, {nx, ny}});
                    }
                }
            }
        }
        
        return -1; // Should never reach here if the grid is well-formed.
    }
};
