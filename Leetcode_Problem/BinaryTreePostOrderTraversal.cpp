/*
145. Binary Tree Postorder Traversal

Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 
*/
class Solution {
public:
    void postorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return; // Base case: if the node is null, return
        
        postorder(root->left, result);  // Traverse the left subtree
        postorder(root->right, result); // Traverse the right subtree
        result.push_back(root->val);    // Visit the root node
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result; // This will store the postorder traversal
        postorder(root, result);
        return result;
    }
};
