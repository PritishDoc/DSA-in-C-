/*
Add Binary Strings
Difficulty: MediumAccuracy: 23.25%Submissions: 71K+Points: 4
Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

Input: s1 = "1101", s2 = "111"
Output: 10100
Explanation:
 1101
+ 111
10100
Input: s1 = "00100", s2 = "010"
Output: 110
Explanation: 
  100
+  10
  110
Constraints:
1 ≤s1.size(), s2.size()≤ 106

*/
class Solution {
public:
    string addBinary(string& s1, string& s2) {
        int n1 = s1.size(), n2 = s2.size();
        int carry = 0;
        string result = "";

        int i = n1 - 1, j = n2 - 1;
        while (i >= 0 || j >= 0 || carry) {
            int bit1 = (i >= 0) ? s1[i--] - '0' : 0; // Get bit from s1 or 0 if out of range
            int bit2 = (j >= 0) ? s2[j--] - '0' : 0; // Get bit from s2 or 0 if out of range

            int sum = bit1 + bit2 + carry; // Add bits and carry
            result.push_back((sum % 2) + '0'); // Append the current bit to result
            carry = sum / 2; // Update carry
        }

        reverse(result.begin(), result.end()); // Reverse the result to get the correct order

        // Remove leading zeros, if any
        size_t pos = result.find_first_not_of('0');
        if (pos != string::npos) {
            return result.substr(pos);
        } else {
            return "0"; // If the result is all zeros
        }
    }
};