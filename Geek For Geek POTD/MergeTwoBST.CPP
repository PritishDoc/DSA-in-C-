/*
Merge two BST 's
Difficulty: MediumAccuracy: 64.95%Submissions: 84K+Points: 4
Given two BSTs, return elements of merged BSTs in sorted form.

Examples :

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
Expected Time Complexity: O((m+n)*log(m+n))
Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

Constraints:
1 ≤ Number of Nodes, value of nodes ≤ 105



*/
class Solution {
  public:
    // Helper function to perform in-order traversal and collect elements
    void inorderTraversal(Node* root, vector<int>& elems) {
        if (root == NULL)
            return;
        inorderTraversal(root->left, elems);
        elems.push_back(root->data);
        inorderTraversal(root->right, elems);
    }

    // Function to merge two sorted vectors into one sorted vector
    vector<int> mergeSortedVectors(const vector<int>& v1, const vector<int>& v2) {
        vector<int> merged;
        int i = 0, j = 0;
        int n1 = v1.size();
        int n2 = v2.size();
        merged.reserve(n1 + n2); // Reserve space to avoid reallocations

        while (i < n1 && j < n2) {
            if (v1[i] <= v2[j]) {
                merged.push_back(v1[i]);
                i++;
            }
            else {
                merged.push_back(v2[j]);
                j++;
            }
        }

        // Append remaining elements from v1
        while (i < n1) {
            merged.push_back(v1[i]);
            i++;
        }

        // Append remaining elements from v2
        while (j < n2) {
            merged.push_back(v2[j]);
            j++;
        }

        return merged;
    }

    // Function to return a list of integers denoting the node
    // values of both the BSTs in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Vector to store in-order traversal of first BST
        vector<int> elems1;
        inorderTraversal(root1, elems1);

        // Vector to store in-order traversal of second BST
        vector<int> elems2;
        inorderTraversal(root2, elems2);

        // Merge the two sorted vectors
        vector<int> mergedList = mergeSortedVectors(elems1, elems2);

        return mergedList;
    }
};