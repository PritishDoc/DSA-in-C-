/*

564. Find the Closest Palindrome

Hint
Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.

The closest is defined as the absolute difference minimized between two integers.

 

Example 1:

Input: n = "123"
Output: "121"
Example 2:

Input: n = "1"
Output: "0"
Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
 

Constraints:

1 <= n.length <= 18
n consists of only digits.
n does not have leading zeros.
n is representing an integer in the range [1, 1018 - 1].
*/
class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        long long original = stoll(n);
        set<long long> candidates;

        // Edge case candidates
        candidates.insert(pow(10, len - 1) - 1); // 999...999 (one less digit)
        candidates.insert(pow(10, len) + 1);     // 1000...0001 (one more digit)

        // Create a prefix from the first half and generate potential palindromes
        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        
        for (int i = -1; i <= 1; ++i) {
            string newPrefix = to_string(prefix + i);
            string palindrome = newPrefix + string(newPrefix.rbegin() + (len % 2), newPrefix.rend());
            candidates.insert(stoll(palindrome));
        }

        // Remove the original number itself
        candidates.erase(original);

        // Find the closest palindrome
        long long closest = -1;
        for (long long candidate : candidates) {
            if (closest == -1 ||
                abs(candidate - original) < abs(closest - original) ||
                (abs(candidate - original) == abs(closest - original) && candidate < closest)) {
                closest = candidate;
            }
        }

        return to_string(closest);
    }
};
