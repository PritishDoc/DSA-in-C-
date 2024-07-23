/*
Rotate Array
Solved
Medium
Topics
Companies
Hint
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        vector<int>temp(nums.size());

        for(int i=0;i<nums.size();i++){
            temp[(i+k)%nums.size()]=nums[i];
        }
        //copy temp into num vector
        nums=temp;

    }
};

/*
i = 0:

nums[i] is 1
Calculate (0 + 3) % 7 = 3
Place 1 in temp[3]
temp = [ , , , 1, , , ]
i = 1:

nums[i] is 2
Calculate (1 + 3) % 7 = 4
Place 2 in temp[4]
temp = [ , , , 1, 2, , ]
i = 2:

nums[i] is 3
Calculate (2 + 3) % 7 = 5
Place 3 in temp[5]
temp = [ , , , 1, 2, 3, ]
i = 3:

nums[i] is 4
Calculate (3 + 3) % 7 = 6
Place 4 in temp[6]
temp = [ , , , 1, 2, 3, 4]
i = 4:

nums[i] is 5
Calculate (4 + 3) % 7 = 0
Place 5 in temp[0]
temp = [5, , , 1, 2, 3, 4]
i = 5:

nums[i] is 6
Calculate (5 + 3) % 7 = 1
Place 6 in temp[1]
temp = [5, 6, , 1, 2, 3, 4]
i = 6:

nums[i] is 7
Calculate (6 + 3) % 7 = 2
Place 7 in temp[2]
temp = [5, 6, 7, 1, 2, 3, 4]
*/