/*

 Trapping Rain Water II
Hard
Topics
Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 

Example 1:


Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.
Example 2:


Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10
 

Constraints:

m == heightMap.length
n == heightMap[i].length
1 <= m, n <= 200
0 <= heightMap[i][j] <= 2 * 104


*/
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0; // No water can be trapped if grid is too small
        
        // Min-heap to store cells by height
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        
        // Visited array
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Push all boundary cells into the heap
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        
        // Directions for 4 neighbors (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        int waterTrapped = 0;
        
        // Process the heap
        while (!minHeap.empty()) {
            auto [height, cell] = minHeap.top();
            minHeap.pop();
            int x = cell.first, y = cell.second;
            
            // Check all 4 neighbors
            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                
                // If the neighbor is valid and not visited
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    // Calculate water trapped
                    waterTrapped += max(0, height - heightMap[nx][ny]);
                    
                    // Update the neighbor's height to the max of its own or the current cell's height
                    minHeap.push({max(height, heightMap[nx][ny]), {nx, ny}});
                    visited[nx][ny] = true;
                }
            }
        }
        
        return waterTrapped;
    }
};
