/*
Largest Number

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109

*/


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert all integers in nums to strings
        vector<string> numStrs;
        for (int num : nums) {
            numStrs.push_back(to_string(num));
        }
        
        // Custom comparator to sort based on the largest concatenation result
        sort(numStrs.begin(), numStrs.end(), [](string &a, string &b) {
            return a + b > b + a;
        });
        
        // If the largest number after sorting is "0", return "0"
        if (numStrs[0] == "0") {
            return "0";
        }
        
        // Join the sorted strings to form the largest number
        string result;
        for (string &numStr : numStrs) {
            result += numStr;
        }
        
        return result;
    }
};