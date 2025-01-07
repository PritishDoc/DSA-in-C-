/*

 String Matching in an Array
Easy
Hint
Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

A substring is a contiguous sequence of characters within a string

 

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
All the strings of words are unique.

*/
#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        int count = 0;

        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == target) {
                // Count duplicates for arr[left]
                int leftCount = 1, rightCount = 1;

                while (left + 1 < right && arr[left] == arr[left + 1]) {
                    leftCount++;
                    left++;
                }

                // Count duplicates for arr[right]
                while (right - 1 > left && arr[right] == arr[right - 1]) {
                    rightCount++;
                    right--;
                }

                if (arr[left] == arr[right]) {
                    // If both pointers point to the same element, handle it
                    count += (leftCount * (leftCount - 1)) / 2;
                } else {
                    // Count pairs formed by leftCount and rightCount
                    count += leftCount * rightCount;
                }

                // Move pointers inward
                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return count;
    }
};
