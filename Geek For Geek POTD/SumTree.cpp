/*
Sum Tree
Difficulty: MediumAccuracy: 37.17%Submissions: 244K+Points: 4
Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.

A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

Examples :

Input:
    3
  /   \    
 1     2
Output: true
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore,the given binary tree is a sum tree.
Input:
          10
        /    \
      20      30
    /   \ 
   10    10
Output: false
Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(Height of the Tree)

Constraints:
2 ≤ number of nodes ≤ 105
1 ≤ node value ≤ 105


*/
/* Tree node structure */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int SumofMiddleElements(std::vector<int> &arr1, std::vector<int> &arr2) {
        int n = arr1.size();
        
        // Ensure arr1 is the smaller array
        if (arr1[0] > arr2[0]) std::swap(arr1, arr2);
        
        int low = 0, high = n;
        
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = n - cut1;
            
            int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            
            int right1 = (cut1 == n) ? INT_MAX : arr1[cut1];
            int right2 = (cut2 == n) ? INT_MAX : arr2[cut2];
            
            if (left1 <= right2 && left2 <= right1) {
                // Found the partition
                return std::max(left1, left2) + std::min(right1, right2);
            } else if (left1 > right2) {
                // We are too far right on arr1, move left
                high = cut1 - 1;
            } else {
                // We are too far left on arr1, move right
                low = cut1 + 1;
            }
        }
        
        return 0;
    }
};

int main() {
    Solution sol;

    std::vector<int> arr1 = {1, 2, 4, 6, 10};
    std::vector<int> arr2 = {4, 5, 6, 9, 12};

    int result = sol.SumofMiddleElements(arr1, arr2);
    std::cout << "Sum of middle elements: " << result << std::endl; // Output: 11

    std::vector<int> arr3 = {1, 12, 15, 26, 38};
    std::vector
