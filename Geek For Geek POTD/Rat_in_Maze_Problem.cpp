/*
Rat in a Maze Problem - I
Difficulty: MediumAccuracy: 35.75%Submissions: 264K+Points: 4
Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

Examples:

Input: mat[][] = [[1, 0, 0, 0],
                [1, 1, 0, 1], 
                [1, 1, 0, 0],
                [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0],
                [1, 0]]
Output: -1
Explanation: No path exists and destination cell is blocked.
Expected Time Complexity: O(3n^2)
Expected Auxiliary Space: O(l * x)
Here l = length of the path, x = number of paths.

Constraints:
2 ≤ n ≤ 5
0 ≤ mat[i][j] ≤ 1
*/
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> result;
        
        if (mat[0][0] == 0 || mat[n-1][n-1] == 0) {
            return result; // No path if start or end is blocked
        }

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string path;
        findPaths(mat, 0, 0, path, result, visited);
        
        sort(result.begin(), result.end()); // Sort paths lexicographically
        return result;
    }

private:
    void findPaths(vector<vector<int>> &mat, int x, int y, string &path, vector<string> &result, vector<vector<bool>> &visited) {
        int n = mat.size();
        if (x == n-1 && y == n-1) {
            result.push_back(path); // Reached destination
            return;
        }

        // Directions: Down, Up, Right, Left
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<char> directionChars = {'D', 'U', 'R', 'L'};

        // Try all four possible directions
        for (int i = 0; i < 4; ++i) {
            int newX = x + directions[i].first;
            int newY = y + directions[i].second;
            if (isSafe(mat, newX, newY, visited)) {
                visited[x][y] = true;
                path.push_back(directionChars[i]);

                findPaths(mat, newX, newY, path, result, visited);

                // Backtrack
                path.pop_back();
                visited[x][y] = false;
            }
        }
    }

    bool isSafe(vector<vector<int>> &mat, int x, int y, vector<vector<bool>> &visited) {
        int n = mat.size();
        return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1 && !visited[x][y]);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends