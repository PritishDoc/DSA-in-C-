/*


Rotate by 90 degree
Difficulty: MediumAccuracy: 66.8%Submissions: 52K+Points: 4
Given a square mat[][]. The task is to rotate it by 90 degrees in clockwise direction without using any extra space.

Examples:

Input: mat[][] = [[1 2 3], [4 5 6], [7 8 9]]
Output:
7 4 1 
8 5 2
9 6 3
Input: mat[][] = [1 2], [3 4]
Output:
3 1 
4 2
Input: mat[][] = [[1]]
Output:
1
Constraints:
1 ≤ mat.size() ≤ 1000
1 <= mat[][] <= 100
*/
void rotate(vector<vector<int>>& mat) {
    int n = mat.size();
    
    // Step 1: Transpose the matrix (swap mat[i][j] with mat[j][i])
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    
    // Step 2: Reverse each row
    for (int i = 0; i < n; ++i) {
        reverse(mat[i].begin(), mat[i].end());
    }
}