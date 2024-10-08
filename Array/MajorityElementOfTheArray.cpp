/*
169. Majority Element
Solved
Easy
Topics
Companies
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
 */

//This is the brute force approch not optimized 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int val:nums){
            int freq=0;//initially set the frequency at zero
            for(int el:nums){
                if(el==val){//while elment is repeating 
                    freq++;//just increase the frequency of that same element
                }
            }
            if(freq>nums.size()/2){//while frequency is greater then the half of the size of the array
                return val;
            }
        }
        return -1;//else
    }
    
};