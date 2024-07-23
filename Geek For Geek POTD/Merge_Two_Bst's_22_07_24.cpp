/*
Merge two BST 's
Difficulty: MediumAccuracy: 64.95%Submissions: 60K+Points: 4
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
Expected Time Complexity: O(M+N) where M and N are the sizes of the two BSTs.
Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + M + N(for storing the answer)).

Constraints:
1 ≤ Number of Nodes ≤ 105
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> sortedList1;
        vector<int> sortedList2;
        
        // Perform in-order traversal on both BSTs
        inOrderTraversal(root1, sortedList1);
        inOrderTraversal(root2, sortedList2);
        
        // Merge the two sorted lists
        return mergeSortedLists(sortedList1, sortedList2);
    }

  private:
    // Helper function to perform in-order traversal
    void inOrderTraversal(Node *root, vector<int>& sortedList) {
        if (!root) return;
        inOrderTraversal(root->left, sortedList);
        sortedList.push_back(root->data);
        inOrderTraversal(root->right, sortedList);
    }
    
    // Helper function to merge two sorted lists
    vector<int> mergeSortedLists(vector<int>& list1, vector<int>& list2) {
        vector<int> mergedList;
        int i = 0, j = 0;
        
        while (i < list1.size() && j < list2.size()) {
            if (list1[i] <= list2[j]) {
                mergedList.push_back(list1[i++]);
            } else {
                mergedList.push_back(list2[j++]);
            }
        }
        
        // Append remaining elements of list1
        while (i < list1.size()) {
            mergedList.push_back(list1[i++]);
        }
        
        // Append remaining elements of list2
        while (j < list2.size()) {
            mergedList.push_back(list2[j++]);
        }
        
        return mergedList;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends