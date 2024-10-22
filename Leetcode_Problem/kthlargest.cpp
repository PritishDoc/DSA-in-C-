/*

 Kth Largest Sum in a Binary Tree
Medium
Topics
Companies
Hint
You are given the root of a binary tree and a positive integer k.

The level sum in the tree is the sum of the values of the nodes that are on the same level.

Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

Note that two nodes are on the same level if they have the same distance from the root.

 

Example 1:


Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.
Example 2:


Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= 106
1 <= k <= n
*/
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        // Min-heap to store the top k largest level sums
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        // Queue for level-order traversal
        queue<TreeNode*> q;
        q.push(root);

        // Perform level-order traversal
        while (!q.empty()) {
            int size = q.size();
            long long levelSum = 0;

            // Sum up all node values at the current level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;

                // Enqueue child nodes for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Push the current level sum to the heap
            minHeap.push(levelSum);

            // If heap size exceeds k, pop the smallest element
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // If there are fewer than k levels, return -1
        if (minHeap.size() < k) return -1;

        // The top of the heap is the Kth largest level sum
        return minHeap.top();
    }
};