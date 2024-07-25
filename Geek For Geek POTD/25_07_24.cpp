/*
Given a sorted array. Convert it into a Height Balanced Binary Search Tree (BST). Return the root of the BST.

Height-balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

Note: The driver code will check the BST, if it is a Height-balanced BST, the output will be true otherwise the output will be false.

Examples :

Input: nums = [1, 2, 3, 4]
Output: true
Explanation: The preorder traversal of the following BST formed is [2, 1, 3, 4]:
           2
         /   \
        1     3
               \
                4
Input: nums = [1, 2, 3, 4, 5, 6, 7]
Ouput: true
Explanation: The preorder traversal of the following BST formed is [4, 2, 1, 3, 6, 5, 7]:
        4
       / \
      2   6
     / \   / \
    1 3  5 7
Expected Time Complexity: O(n)
Expected Auxillary Space: O(n)

Constraints:
1 ≤ nums.size() ≤ 105
1 ≤ nums[i] ≤ 105
*/

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Node* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    Node* buildBST(const vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        Node* node = new Node(nums[mid]);

        node->left = buildBST(nums, start, mid - 1);
        node->right = buildBST(nums, mid + 1, end);

        return node;
    }
};

// Function to print preorder traversal of the BST
void preOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

// Driver code
int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 4};
    Node* root1 = solution.sortedArrayToBST(nums1);
    cout << "Preorder traversal of BST formed from [1, 2, 3, 4]: ";
    preOrder(root1);
    cout << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7};
    Node* root2 = solution.sortedArrayToBST(nums2);
    cout << "Preorder traversal of BST formed from [1, 2, 3, 4, 5, 6, 7]: ";
    preOrder(root2);
    cout << endl;

    return 0;
}
