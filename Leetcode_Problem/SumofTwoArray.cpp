/*
Add to Array-Form of Integer
Solved
Easy
Topics
Companies
The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

 

Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
 

Constraints:

1 <= num.length <= 104
0 <= num[i] <= 9
num does not contain any leading zeros except for the zero itself.
1 <= k <= 104
*/

class Solution {
public:
    std::vector<int> addToArrayForm(std::vector<int>& num, int k) {
        int n = num.size();
        int carry = 0;
        std::vector<int> result;
        
        for (int i = n - 1; i >= 0 || k > 0; --i) {
            if (i >= 0) {
                carry += num[i];
            }
            carry += k % 10;
            k /= 10;
            result.push_back(carry % 10);
            carry /= 10;
        }
        
        if (carry > 0) {
            result.push_back(carry);
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};

/*
Input:

num = [2, 1, 5]
k = 806
Expected Output: [1, 0, 2, 1] (since 215 + 806 = 1021)

Step-by-Step Explanation
Initialization:

num = [2, 1, 5]
k = 806
carry = 0
result = []
First Iteration (rightmost digit of num):

i = 2 (last index of num)
num[i] = 5
k % 10 = 6
Add 5 (from num) and 6 (last digit of k): carry = 5 + 6 = 11
Push carry % 10 = 11 % 10 = 1 to result: result = [1]
Update carry with carry / 10 = 11 / 10 = 1
Remove the last digit of k: k = 806 / 10 = 80
Second Iteration:

i = 1
num[i] = 1
k % 10 = 0
Add 1 (from num) and 0 (last digit of k) with carry: carry = 1 + 0 + 1 = 2
Push carry % 10 = 2 % 10 = 2 to result: result = [1, 2]
Update carry with carry / 10 = 2 / 10 = 0
Remove the last digit of k: k = 80 / 10 = 8
Third Iteration:

i = 0
num[i] = 2
k % 10 = 8
Add 2 (from num) and 8 (last digit of k): carry = 2 + 8 = 10
Push carry % 10 = 10 % 10 = 0 to result: result = [1, 2, 0]
Update carry with carry / 10 = 10 / 10 = 1
Remove the last digit of k: k = 8 / 10 = 0
After Iterating Through num:

k is now 0, but carry is 1.
Push carry to result: result = [1, 2, 0, 1]
No more digits left in num or k.
Reverse the result:

result is currently [1, 2, 0, 1] (which is in reverse order).
Reverse result: result = [1, 0, 2, 1]
Final Result
The final array-form of the integer after addition is [1, 0, 2, 1].
*/