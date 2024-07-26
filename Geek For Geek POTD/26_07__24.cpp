/*
Given a string str and an integer k, return true if the string can be changed into a pangram after at most k operations, else return false.

A single operation consists of swapping an existing alphabetic character with any other lowercase alphabetic character.

Note - A pangram is a sentence containing every letter in the english alphabet.

Examples :

Input: str = "the quick brown fox jumps over the lazy dog", k = 0
Output: true
Explanation: the sentence contains all 26 characters and is already a pangram.
Input: str = "aaaaaaaaaaaaaaaaaaaaaaaaaa", k = 25 
Output: true
Explanation: The word contains 26 instances of 'a'. Since only 25 operations are allowed. We can keep 1 instance and change all others to make str a pangram.
Input: str = "a b c d e f g h i j k l m", k = 20
Output: false
Explanation: Since there are only 13 alphabetic characters in this case, no amount of swapping can produce a panagram here.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)  


*/
class Solution {
  public:
    bool kPangram(string str, int k) {
        // Removing spaces from the string
        for (int i = 0; i < str.length(); i++)
            if (str[i] == ' ')
                str.erase(str.begin() + i);

        // If the length of the string is less than 26, it can't be a pangram
        if (str.length() < 26)
            return false;

        // If k is greater than 25, it will always be a pangram
        if (k > 25)
            return true;
        else {
            // Creating a map to store occurrence of each character in the string
            int map[26] = {0};

            // Updating the map with occurrence of each character
            for (int i = 0; i < str.length(); i++)
                map[str[i] - 'a'] = 1;

            // Counting the number of distinct characters in the string
            int count = 0;
            for (int i = 0; i < 26; i++) {
                if (map[i] == 1)
                    count++;
            }

            // Checking if the number of distinct characters plus k is at least 26
            if (count + k >= 26)
                return true;
            else
                return false;
        }
    }
};