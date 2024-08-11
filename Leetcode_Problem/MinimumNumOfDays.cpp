/*
Minimum Number of Days to Disconnect Island
Hard
Topics
Companies
Hint
You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.

 

Example 1:


Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
Example 2:


Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 30
grid[i][j] is either 0 or 1.

*/

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Declare dfs lambda
        std::function<void(int, int, vector<vector<int>>&)> dfs;

        // Define the dfs lambda
        dfs = [&](int i, int j, vector<vector<int>>& g) {
            if (i < 0 || j < 0 || i >= m || j >= n || g[i][j] == 0) return;
            g[i][j] = 0; // Mark the land as visited by setting it to 0
            dfs(i + 1, j, g);
            dfs(i - 1, j, g);
            dfs(i, j + 1, g);
            dfs(i, j - 1, g);
        };

        // Function to check if the grid is connected (1 island) or not
        auto isConnected = [&]() {
            vector<vector<int>> g = grid;
            int islands = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (g[i][j] == 1) {
                        islands++;
                        if (islands > 1) return false; // More than 1 island
                        dfs(i, j, g);
                    }
                }
            }
            return islands == 1; // Return true if exactly 1 island
        };

        // If already disconnected, return 0
        if (!isConnected()) return 0;

        // Try removing one cell and check connectivity
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; // Temporarily remove the land
                    if (!isConnected()) return 1;
                    grid[i][j] = 1; // Restore the land
                }
            }
        }

        // If removing one cell didn't work, try two cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    for (int x = 0; x < m; x++) {
                        for (int y = 0; y < n; y++) {
                            if (grid[x][y] == 1) {
                                grid[x][y] = 0;
                                if (!isConnected()) return 2;
                                grid[x][y] = 1;
                            }
                        }
                    }
                    grid[i][j] = 1;
                }
            }
        }

        return 2; // Worst-case scenario
    }
};