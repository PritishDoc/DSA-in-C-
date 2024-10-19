/*

 Find Kth Bit in Nth Binary String
Medium
Topics
Companies
Hint
Given two positive integers n and k, the binary string Sn is formed as follows:

S1 = "0"
Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first four strings in the above sequence are:

S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

 

Example 1:

Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001".
The 1st bit is "0".
Example 2:

Input: n = 4, k = 11
Output: "1"
Explanation: S4 is "011100110110001".
The 11th bit is "1".
 

Constraints:

1 <= n <= 20
1 <= k <= 2n - 1
*/
class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case: S1 is just "0"
        if (n == 1) return '0';
        
        int length = (1 << n) - 1;  // Length of Sn = 2^n - 1
        int mid = length / 2 + 1;   // Middle position is (2^n) / 2
        
        if (k == mid) {
            return '1';  // Middle bit is always '1'
        } else if (k < mid) {
            // If k is in the first half, it corresponds to the kth bit in S_{n-1}
            return findKthBit(n - 1, k);
        } else {
            // If k is in the second half, it corresponds to the reverse of inverted S_{n-1}
            // Map k to the corresponding position in the first half
            int mirrorIndex = length - k + 1;
            char mirrorBit = findKthBit(n - 1, mirrorIndex);
            // Invert the bit
            return mirrorBit == '0' ? '1' : '0';
        }
    }
};
