/*
Bottom View of Binary Tree
Difficulty: MediumAccuracy: 54.18%Submissions: 247K+Points: 4
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree, the output should be 5 10 4 14 25.

Examples :

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        if (!root) return {};

        // This map stores the horizontal distance and the corresponding bottommost node's value
        map<int, int> hdNodeMap;

        // Queue to perform level order traversal. Stores pairs of node and its horizontal distance
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            Node *node = front.first;
            int hd = front.second;

            // Update the map with the current node for its horizontal distance
            hdNodeMap[hd] = node->data;

            // Push left child with horizontal distance - 1
            if (node->left) {
                q.push({node->left, hd - 1});
            }

            // Push right child with horizontal distance + 1
            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        // Extract the bottom view from the map and return it
        vector<int> bottomView;
        for (auto it : hdNodeMap) {
            bottomView.push_back(it.second);
        }

        return bottomView;
    }
};

// Helper function to build a tree for testing
Node* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    Node* root = new Node(nodes[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        Node* current = q.front();
        q.pop();

        if (nodes[i] != -1) {
            current->left = new Node(nodes[i]);
            q.push(current->left);
        }
        i++;
        if (i >= nodes.size()) break;

        if (nodes[i] != -1) {
            current->right = new Node(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Main function for testing
int main() {
    Solution solution;

    vector<int> nodes1 = {1, 3, 2};
    Node* root1 = buildTree(nodes1);
    vector<int> result1 = solution.bottomView(root1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nodes2 = {10, 20, 30, 40, 60};
    Node* root2 = buildTree(nodes2);
    vector<int> result2 = solution.bottomView(root2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
