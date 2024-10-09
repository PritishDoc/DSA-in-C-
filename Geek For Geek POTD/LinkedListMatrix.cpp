/*
Linked List Matrix
Difficulty: EasyAccuracy: 67.33%Submissions: 27K+Points: 2
Given a Matrix mat of n*n size. Your task is constructing a 2D linked list representation of the given matrix.

Input: mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 

Input: mat = [[23, 28], [23, 28]]
Output:

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)

Constraints:
1 <= mat.size() <=15
1 <= mat[i][j] <=104
*/
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        if (mat.empty()) return NULL;
        
        int n = mat.size();
        vector<vector<Node*>> nodeMatrix(n, vector<Node*>(n, NULL));
        
        // Create all nodes for the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                nodeMatrix[i][j] = new Node(mat[i][j]);
            }
        }
        
        // Connect the right and down pointers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j + 1 < n) {
                    nodeMatrix[i][j]->right = nodeMatrix[i][j + 1];
                }
                if (i + 1 < n) {
                    nodeMatrix[i][j]->down = nodeMatrix[i + 1][j];
                }
            }
        }
        
        // Return the pointer to the first element (top-left)
        return nodeMatrix[0][0];
    }
};