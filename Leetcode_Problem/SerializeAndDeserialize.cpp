/*


Serialize and deserialize a binary tree
Difficulty: MediumAccuracy: 51.67%Submissions: 90K+Points: 4Average Time: 45m
Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

serialize() : stores the tree into an array a and returns the array.
deSerialize() : deserializes the array to the tree and returns the root of the tree.
Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).

Examples :

Input: root = [1, 2, 3]
      
Output: [2, 1, 3]
Input: root = [10, 20, 30, 40, 60, N, N]
      
Output: [40, 20, 60, 10, 30]
Constraints:
1 <= Number of nodes <= 104
1 <= Data of a node <= 109


*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
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
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node* root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node) {
                result.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            } else {
                result.push_back(-1); // Using -1 to represent NULL
            }
        }
        return result;
    }

    // Function to deserialize a list and construct the tree.
    Node* deSerialize(vector<int>& arr) {
        if (arr.empty()) return NULL;

        queue<Node*> q;
        Node* root = new Node(arr[0]);
        q.push(root);
        int i = 1;

        while (!q.empty() && i < arr.size()) {
            Node* curr = q.front();
            q.pop();

            if (arr[i] != -1) {
                curr->left = new Node(arr[i]);
                q.push(curr->left);
            }
            i++;

            if (i < arr.size() && arr[i] != -1) {
                curr->right = new Node(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};

// Helper function for inorder traversal
void inorder(Node* root, vector<int>& res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}

int main() {
    Solution sol;

    // Example tree: [10, 20, 30, 40, 60, N, N]
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    vector<int> serializedTree = sol.serialize(root);
    Node* deserializedTree = sol.deSerialize(serializedTree);

    vector<int> inorderResult;
    inorder(deserializedTree, inorderResult);

    for (int val : inorderResult) {
        cout << val << " ";
    }
    return 0;
}
