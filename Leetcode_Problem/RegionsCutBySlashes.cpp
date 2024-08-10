/*
 Regions Cut By Slashes

An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

 

Example 1:


Input: grid = [" /","/ "]
Output: 2
Example 2:


Input: grid = [" /","  "]
Output: 1
Example 3:


Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 30
grid[i][j] is either '/', '\', or ' '.
*/

class Solution {
public:
    int regionsBySlashes(std::vector<std::string>& grid) {
        int n = grid.size();
        int size = n * n * 4;
        std::vector<int> parent(size);
        
        // Initialize Union-Find (Disjoint Set Union)
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }

        // Find function with path compression
        std::function<int(int)> find = [&](int x) -> int {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        // Union function
        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootX] = rootY;
            }
        };

        // Iterate over the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int base = (i * n + j) * 4;
                char c = grid[i][j];

                // Connect within the cell
                if (c == '/') {
                    unite(base + 0, base + 3);
                    unite(base + 1, base + 2);
                } else if (c == '\\') {
                    unite(base + 0, base + 1);
                    unite(base + 2, base + 3);
                } else {
                    unite(base + 0, base + 1);
                    unite(base + 1, base + 2);
                    unite(base + 2, base + 3);
                }

                // Connect with the right cell
                if (j + 1 < n) {
                    unite(base + 1, base + 4 + 3);
                }

                // Connect with the bottom cell
                if (i + 1 < n) {
                    unite(base + 2, base + n * 4 + 0);
                }
            }
        }

        // Count the number of regions
        int regions = 0;
        for (int i = 0; i < size; ++i) {
            if (find(i) == i) {
                regions++;
            }
        }

        return regions;
    }
};