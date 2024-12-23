/*
 Minimum Number of Operations to Sort a Binary Tree by Level
Hint
You are given the root of a binary tree with unique values.

In one operation, you can choose any two nodes at the same level and swap their values.

Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.

The level of a node is the number of edges along the path between it and the root node.

 

Example 1:


Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
Output: 3
Explanation:
- Swap 4 and 3. The 2nd level becomes [3,4].
- Swap 7 and 5. The 3rd level becomes [5,6,8,7].
- Swap 8 and 7. The 3rd level becomes [5,6,7,8].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.
Example 2:


Input: root = [1,3,2,7,6,5,4]
Output: 3
Explanation:
- Swap 3 and 2. The 2nd level becomes [2,3].
- Swap 7 and 4. The 3rd level becomes [4,6,5,7].
- Swap 6 and 5. The 3rd level becomes [4,5,6,7].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.
Example 3:


Input: root = [1,2,3,4,5,6]
Output: 0
Explanation: Each level is already sorted in increasing order so return 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
All the values of the tree are unique.

*/
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;
        
        // Helper function to calculate minimum swaps to sort an array
        auto minSwapsToSort = [](vector<int>& arr) {
            int n = arr.size();
            vector<pair<int, int>> valueIndex;
            for (int i = 0; i < n; ++i) {
                valueIndex.emplace_back(arr[i], i);
            }
            
            // Sort the array by value
            sort(valueIndex.begin(), valueIndex.end());
            
            vector<bool> visited(n, false);
            int swaps = 0;
            
            for (int i = 0; i < n; ++i) {
                if (visited[i] || valueIndex[i].second == i) continue;
                
                int cycleSize = 0;
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = valueIndex[j].second;
                    cycleSize++;
                }
                
                if (cycleSize > 1) {
                    swaps += cycleSize - 1;
                }
            }
            
            return swaps;
        };
        
        queue<TreeNode*> q;
        q.push(root);
        int totalSwaps = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelValues;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Calculate swaps needed for the current level
            totalSwaps += minSwapsToSort(levelValues);
        }
        
        return totalSwaps;
    }
};