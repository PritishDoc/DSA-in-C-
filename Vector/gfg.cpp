/*
Level order traversal
Difficulty: EasyAccuracy: 70.31%Submissions: 222K+Points: 2
Given a root of a binary tree with n nodes, the task is to find its level order traversal. Level order traversal of a tree is breadth-first traversal for the tree.

Examples:

Input: root[] = [1, 2, 3]

Output: [[1], [2, 3]]
Input: root[] = [10, 20, 30, 40, 50]

Output: [[10], [20, 30], [40, 50]]
Input: root[] = [1, 3, 2, N, N, N, 4, 6, 5]

Output: [[1], [3, 2], [4], [6, 5]]
Constraints:

1 ≤ number of nodes ≤ 105
0 ≤ node->data ≤ 109

*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int count =0;
        int n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                count++;
            }

        }
        if(nums[n-1]>nums[0])
            count++;
          return count<=1;
        

    }
};