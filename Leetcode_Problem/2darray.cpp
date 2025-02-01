/*

Word Search
Difficulty: MediumAccuracy: 32.69%Submissions: 63K+Points: 4
You are given a two-dimensional mat[][] of size n*m containing English alphabets and a string word. Check if the word exists on the mat. The word can be constructed by using letters from adjacent cells, either horizontally or vertically. The same cell cannot be used more than once.

Examples :

Input: mat[][] = [['T', 'E', 'E'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
Output: true
Explanation:

The letter cells which are used to construct the "GEEK" are colored.
Input: mat[][] = [['T', 'E', 'U'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
Output: false
Explanation:

It is impossible to construct the string word from the mat using each cell only once.
Input: mat[][] = [['A', 'B', 'A'], ['B', 'A', 'B']], word = "AB"
Output: true
Explanation:

There are multiple ways to construct the word "AB".
Constraints:
1 ≤ n, m ≤ 6
1 ≤ L ≤ 15
mat and word consists of only lowercase and uppercase English letters.

*/
class Solution {
public:
    bool dfs(vector<vector<char>>& mat, string& word, int i, int j, int index, vector<vector<bool>>& visited) {
        if (index == word.length()) return true; // Word is completely found
        
        int n = mat.size();
        int m = mat[0].size();
        
        if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != word[index] || visited[i][j])
            return false;
        
        visited[i][j] = true;
        
        // Explore all 4 possible directions (up, down, left, right)
        bool found = dfs(mat, word, i + 1, j, index + 1, visited) ||
                     dfs(mat, word, i - 1, j, index + 1, visited) ||
                     dfs(mat, word, i, j + 1, index + 1, visited) ||
                     dfs(mat, word, i, j - 1, index + 1, visited);
        
        visited[i][j] = false; // Backtrack
        return found;
    }
    
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) { // Start DFS from matching first letter
                    if (dfs(mat, word, i, j, 0, visited)) return true;
                }
            }
        }
        return false;
    }
};
