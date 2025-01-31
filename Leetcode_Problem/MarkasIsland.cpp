/*
 Making A Large Island
Hard
Topics
Companies
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.


*/
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        unordered_map<int, int> areaMap;
        int index = 2, maxArea = 0;

        // DFS function to calculate island size
        function<int(int, int, int)> dfs = [&](int r, int c, int index) {
            if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1) return 0;
            grid[r][c] = index;
            int area = 1;
            for (auto& dir : directions) {
                area += dfs(r + dir[0], c + dir[1], index);
            }
            return area;
        };

        // Step 1: Label each island and record its size
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    areaMap[index] = dfs(i, j, index);
                    maxArea = max(maxArea, areaMap[index]);
                    index++;
                }
            }
        }

        // Step 2: Try flipping each 0 and compute possible max island size
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int newArea = 1; // Include the flipped cell
                    for (auto& dir : directions) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1) {
                            int islandIndex = grid[ni][nj];
                            if (seen.count(islandIndex) == 0) {
                                newArea += areaMap[islandIndex];
                                seen.insert(islandIndex);
                            }
                        }
                    }
                    maxArea = max(maxArea, newArea);
                }
            }
        }

        return maxArea;
    }
};