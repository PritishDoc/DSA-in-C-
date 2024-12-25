/*
Find Largest Value in Each Tree Row
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-231 <= Node.val <= 231 - 1
*/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (!root) return result; // Return an empty vector if the tree is empty

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int maxVal = INT_MIN;

            // Process all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Update the maximum value for the current level
                maxVal = max(maxVal, node->val);

                // Add child nodes to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Add the largest value of the current level to the result
            result.push_back(maxVal);
        }

        return result;
    }
};