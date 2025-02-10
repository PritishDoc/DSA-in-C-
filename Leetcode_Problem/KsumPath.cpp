
/*

K Sum Paths
Difficulty: MediumAccuracy: 44.73%Submissions: 106K+Points: 4
Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. A path can start and end at any node within the tree but must always move downward (from parent to child).

Examples:

Input: k = 7   

Output: 3
Explanation: The following paths sum to k 
 
Input: k = 3
   1
  /  \
2     3
Output: 2
Explanation:
Path 1 : 1 -> 2 (Sum = 3)
Path 2 : 3 (Sum = 3)
Constraints:

1 ≤ number of nodes ≤ 104
-100 ≤ node value ≤ 100
-109 ≤ k ≤ 109


*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    int count = 0;
    
    void dfs(Node* root, int k, long long currSum, unordered_map<long long, int>& prefixSumMap) {
        if (!root) return;

        // Update current prefix sum
        currSum += root->data;

        // Check if there's a prefix sum that forms a valid path sum
        if (prefixSumMap.find(currSum - k) != prefixSumMap.end()) {
            count += prefixSumMap[currSum - k];
        }

        // Include the current prefix sum in the map
        prefixSumMap[currSum]++;

        // Recur for left and right subtrees
        dfs(root->left, k, currSum, prefixSumMap);
        dfs(root->right, k, currSum, prefixSumMap);

        // Backtrack: remove the current sum from map
        prefixSumMap[currSum]--;
    }

    int sumK(Node *root, int k) {
        unordered_map<long long, int> prefixSumMap;
        prefixSumMap[0] = 1; // Base case: sum from root to this point is exactly k
        dfs(root, k, 0, prefixSumMap);
        return count;
    }
};
