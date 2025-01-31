/*
Spiral Matrix III

You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.

 

Example 1:


Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]
Example 2:


Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2
*/

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        vector<int> dirX = {0, 1, 0, -1}; // Right, Down, Left, Up (row change)
        vector<int> dirY = {1, 0, -1, 0}; // Right, Down, Left, Up (column change)
        
        int numSteps = 1; // Number of steps in the current direction
        int dirIndex = 0; // Current direction index
        int totalCells = rows * cols;
        
        result.push_back({rStart, cStart}); // Add the starting position
        int count = 1; // Start with one cell visited
        
        while (count < totalCells) {
            for (int i = 0; i < 2; ++i) { // Each step size is repeated twice (once for each direction)
                for (int j = 0; j < numSteps; ++j) {
                    // Move in the current direction
                    rStart += dirX[dirIndex];
                    cStart += dirY[dirIndex];
                    
                    // Check if within bounds and add to result
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        result.push_back({rStart, cStart});
                        count++;
                        if (count == totalCells) return result;
                    }
                }
                // Change direction (right -> down -> left -> up)
                dirIndex = (dirIndex + 1) % 4;
            }
            // Increase step size after a full cycle of direction changes
            numSteps++;
        }
        
        return result;
    }
};