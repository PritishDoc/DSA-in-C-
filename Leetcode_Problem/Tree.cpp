#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;
    
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    unordered_map<int, int> inorderIndexMap;
    int preorderIndex = 0;

    // Helper function to build the tree recursively
    Node* buildTreeHelper(vector<int>& inorder, vector<int>& preorder, int start, int end) {
        if (start > end) return NULL;

        // Pick current root from preorder traversal
        int rootValue = preorder[preorderIndex++];
        Node* root = new Node(rootValue);

        // Get the index of root in inorder traversal
        int inorderIndex = inorderIndexMap[rootValue];

        // Build left and right subtrees
        root->left = buildTreeHelper(inorder, preorder, start, inorderIndex - 1);
        root->right = buildTreeHelper(inorder, preorder, inorderIndex + 1, end);

        return root;
    }

    // Function to build the tree
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        int n = inorder.size();

        // Store inorder indices for quick access
        for (int i = 0; i < n; i++) {
            inorderIndexMap[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, preorder, 0, n - 1);
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (!root) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// Driver Code
int main() {
    Solution sol;
    vector<int> inorder = {2, 5, 4, 1, 3};
    vector<int> preorder = {1, 4, 5, 2, 3};

    Node* root = sol.buildTree(inorder, preorder);

    // Print postorder traversal of constructed tree
    printPostOrder(root);
    cout << endl;

    return 0;
}
