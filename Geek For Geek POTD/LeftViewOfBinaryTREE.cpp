/*
Left View of Binary Tree
Difficulty: EasyAccuracy: 33.74%Submissions: 508K+Points: 2
Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Examples :

Input:
   1
 /  \
3    2
Output: 1 3

Input:

Output: 10 20 40
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 105
0 <= Data of a node <= 105
*/
vector<int> leftView(Node *root) {
    vector<int> result;
    if (!root) return result;  // If tree is empty, return an empty list
    
    queue<Node*> q;  // Create a queue for level order traversal
    q.push(root);
    
    while (!q.empty()) {
        int n = q.size();  // Number of nodes at the current level
        
        // Traverse all nodes of the current level
        for (int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();
            
            // If this is the first node of the current level, add it to the result
            if (i == 0) {
                result.push_back(curr->data);
            }
            
            // Enqueue the left and right children of the current node
            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }
        }
    }
    
    return result;  // Return the left view of the binary tree
}