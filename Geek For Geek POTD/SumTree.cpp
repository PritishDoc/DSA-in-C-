/*
Sum Tree
Difficulty: MediumAccuracy: 37.17%Submissions: 244K+Points: 4
Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.

A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

Examples :

Input:
    3
  /   \    
 1     2
Output: true
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore,the given binary tree is a sum tree.
Input:
          10
        /    \
      20      30
    /   \ 
   10    10
Output: false
Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(Height of the Tree)

Constraints:
2 ≤ number of nodes ≤ 105
1 ≤ node value ≤ 105


*/
/* Tree node structure */
struct Node {
    int data;
    Node* left, * right;
};

class Solution {
public:
    // Helper function to check Sum Tree and return sum of the subtree
    int checkSumTree(Node* node, bool& isSumTree) {
        // Base case: If node is NULL, return sum as 0
        if (node == nullptr) {
            return 0;
        }

        // If node is a leaf node, return its own value
        if (node->left == nullptr && node->right == nullptr) {
            return node->data;
        }

        // Recur for left and right subtrees
        int leftSum = checkSumTree(node->left, isSumTree);
        int rightSum = checkSumTree(node->right, isSumTree);

        // Check if the current node's data is equal to sum of its left and right subtree
        if (node->data != leftSum + rightSum) {
            isSumTree = false;
        }

        // Return the sum of values under the current subtree rooted at `node`
        return node->data + leftSum + rightSum;
    }

    bool isSumTree(Node* root) {
        // Variable to keep track if the tree is Sum Tree or not
        bool isSumTreeFlag = true;

        // Helper function call to initialize the recursion
        checkSumTree(root, isSumTreeFlag);

        return isSumTreeFlag;
    }
};
