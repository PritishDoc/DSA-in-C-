/*
Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
Note: Here Size equals the number of nodes in the subtree.

Examples :

Input:   1
        /  \
        4   4              
       / \ 
      6   8
Output: 1 
Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.

Input:    6
        /   \
      6      2              
       \    / \
        2  1   3
Output: 3
Explanation: The following sub-tree is a BST of size 3:  2
                                                       /   \
                                                      1     3
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106


*/
//code........
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    // Helper function to find the largest BST
    struct Info {
        int size;     // Size of subtree
        int min;      // Minimum value in subtree
        int max;      // Maximum value in subtree
        int largest_bst_size; // Size of the largest BST which is subtree of current node
        bool is_bst;  // If subtree is BST
    };
    
    Info largestBstUtil(Node* root) {
        // Base case: An empty tree is a BST of size 0
        if (root == NULL) {
            return {0, INT_MAX, INT_MIN, 0, true};
        }
        
        // Recursively get info from left and right subtrees
        Info left = largestBstUtil(root->left);
        Info right = largestBstUtil(root->right);
        
        Info curr;
        curr.size = 1 + left.size + right.size;
        
        // If both left and right subtrees are BSTs and the current node's value is greater than max value in the left subtree
        // and less than min value in the right subtree, then it's a BST.
        if (left.is_bst && right.is_bst && root->data > left.max && root->data < right.min) {
            curr.min = std::min(left.min, root->data);
            curr.max = std::max(right.max, root->data);
            
            curr.largest_bst_size = curr.size;
            curr.is_bst = true;
        } else {
            curr.largest_bst_size = std::max(left.largest_bst_size, right.largest_bst_size);
            curr.is_bst = false;
        }
        
        return curr;
    }
    
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        return largestBstUtil(root).largest_bst_size;
    }
};