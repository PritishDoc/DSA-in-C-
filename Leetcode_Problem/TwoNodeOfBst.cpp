/*
Fixing Two nodes of a BST
Difficulty: HardAccuracy: 53.68%Submissions: 50K+Points: 8Average Time: 45m
Given the root of a Binary search tree(BST), where exactly two nodes were swapped by mistake. Your task is to fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original linked list.
 
Examples :
Input: root = [10, 5, 8, 2, 20]
     
Output: 1
       

Explanation: The nodes 20 and 8 were swapped. 
Input: root = [5, 10, 20, 2, 8]
     
Output: 1 
     
Explanation: The nodes 10 and 5 were swapped.
Constraints:
1 ≤ Number of nodes ≤ 103


*/class Solution {
public:
Node *first = NULL, *middle = NULL, *last = NULL, *prev = NULL;

void inorder(Node* root) {
    if (!root) return;

    inorder(root->left);

    // Detect swapped nodes
    if (prev && root->data < prev->data) {
        if (!first) {  // First occurrence
            first = prev;
            middle = root;
        } else {  // Second occurrence
            last = root;
        }
    }

    prev = root; // Update previous node
    inorder(root->right);
}

void correctBST(Node* root) {
    inorder(root);

    // Swap values
    if (first && last) swap(first->data, last->data);  // Case 1: Non-adjacent swap
    else if (first && middle) swap(first->data, middle->data);  // Case 2: Adjacent swap
}
};
