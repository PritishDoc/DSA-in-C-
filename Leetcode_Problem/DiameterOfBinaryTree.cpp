/*
Diameter of a Binary Tree
Difficulty: MediumAccuracy: 47.37%Submissions: 320K+Points: 4Average Time: 20m
Given a binary tree, the diameter (also known as the width) is defined as the number of edges on the longest path between two leaf nodes in the tree. This path may or may not pass through the root. Your task is to find the diameter of the tree.

Examples:

Input: root[] = [1, 2, 3]

Output: 2
Explanation: The longest path has 2 edges (node 2 -> node 1 -> node 3).

Input: root[] = [5, 8, 6, 3, 7, 9]

Output: 4
Explanation: The longest path has 4 edges (node 3 -> node 8 -> node 5 -> node 6 -> node 9).

Constraints:
1 ≤ number of nodes ≤ 105
0 ≤ node->data ≤ 105




*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    int maxDiameter = 0;

    int findHeight(Node* root) {
        if (!root) return 0;

        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        // Update the maximum diameter
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameter(Node* root) {
        maxDiameter = 0; // Reset before computation
        findHeight(root);
        return maxDiameter;
    }
};

// Utility function to create a new node
Node* newNode(int val) {
    return new Node(val);
}

// Driver code
int main() {
    Node* root = newNode(5);
    root->left = newNode(8);
    root->right = newNode(6);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(9);

    Solution sol;
    cout << "Diameter of the tree: " << sol.diameter(root) << endl;

    return 0;
}
