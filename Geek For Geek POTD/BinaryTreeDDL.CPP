/*
Binary Tree to DLL
Difficulty: HardAccuracy: 53.36%Submissions: 148K+Points: 8
Given a Binary Tree (BT), convert it to a Doubly Linked List (DLL) in place. The left and right pointers in nodes will be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as the order of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Note: h is the tree's height, and this space is used implicitly for the recursion stack.

TreeToList

Examples:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3

Explanation: DLL would be 3<=>1<=>2
Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40

Explanation:  DLL would be 40<=>20<=>60<=>10<=>30.
Expected Time Complexity: O(no. of nodes)
Expected Space Complexity: O(height of the tree)

Constraints:
1 ≤ Number of nodes ≤ 105
0 ≤ Data of a node ≤ 105
*/
class Solution {
public:
    Node* prev = NULL; // To track the previous node
    Node* head = NULL; // To store the head of the DLL

    // Utility function to convert binary tree to DLL
    void inorderTraversal(Node* root) {
        if (!root) return;

        // Recursively convert the left subtree
        inorderTraversal(root->left);

        // Now convert the current node
        if (prev == NULL) {
            // If prev is NULL, this is the leftmost node (head of DLL)
            head = root;
        } else {
            // Adjust the pointers to link the previous node with the current one
            prev->right = root;
            root->left = prev;
        }
        // Move prev to current node
        prev = root;

        // Recursively convert the right subtree
        inorderTraversal(root->right);
    }

    // This function returns the head of the DLL
    Node* bToDLL(Node* root) {
        if (!root) return NULL;

        // Perform the inorder traversal to convert the tree to DLL
        inorderTraversal(root);

        // Return the head of the DLL
        return head;
    }
};