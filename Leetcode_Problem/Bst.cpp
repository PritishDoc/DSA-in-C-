/*
Pair Sum in BST
Difficulty: MediumAccuracy: 44.02%Submissions: 72K+Points: 4Average Time: 40m
Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target. 

Examples:

Input: root = [7, 3, 8, 2, 4, N, 9], target = 12
       bst
Output: True
Explanation: In the binary tree above, there are two nodes (8 and 4) that add up to 12.
Input: root = [9, 5, 10, 2, 6, N, 12], target = 23
          bst-3
Output: False
Explanation: In the binary tree above, there are no such two nodes exists that add up to 23.
Constraints:

1 ≤ Number of Nodes ≤ 105
1 ≤ target ≤ 106

*/

#include <unordered_set>

class Solution {
  public:
    bool findPair(Node* root, int target, unordered_set<int>& s) {
        if (!root) return false;
        
        // Check left subtree
        if (findPair(root->left, target, s)) return true;
        
        // Check if (target - current node's value) exists in the set
        if (s.find(target - root->data) != s.end()) return true;
        
        // Insert current node's value into the set
        s.insert(root->data);
        
        // Check right subtree
        return findPair(root->right, target, s);
    }

    bool findTarget(Node *root, int target) {
        unordered_set<int> s;
        return findPair(root, target, s);
    }
};
