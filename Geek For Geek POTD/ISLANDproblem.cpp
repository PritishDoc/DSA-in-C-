/*

Find the number of islands
Difficulty: MediumAccuracy: 42.12%Submissions: 209K+Points: 4
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Examples:

Input: grid = [[0,1],[1,0],[1,1],[1,0]]
Output: 1
Explanation:
The grid is-

All lands are connected.
Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]
Output: 2
Expanation:
The grid is-
 
There are two islands :- one is colored in "blue" and other in "red".
Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] = {'0', '1'}
*/
#include <vector>
using namespace std;

class Solution {
public:
    // Directions for 8 neighboring cells (including diagonals)
    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1},  {1, 0}, {1, 1}
    };
    
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Mark the current cell as visited
        visited[row][col] = true;
        
        // Explore all 8 directions
        for(auto &dir : directions){
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            
            // Check if the new position is within bounds, is land, and not visited
            if(newRow >=0 && newRow < n && newCol >=0 && newCol < m &&
               grid[newRow][newCol] == '1' && !visited[newRow][newCol]){
                dfs(newRow, newCol, grid, visited);
            }
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        int islandCount = 0;
        

        // Initialize visited matrix
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // Traverse each cell in the grid
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                // If the cell is land and not visited, it's part of a new island
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(i, j, grid, visited);
                    islandCount++;
                }
            }
        }
        
        return islandCount;
    }
};
