/*
Reverse Words
Difficulty: EasyAccuracy: 56.08%Submissions: 331K+Points: 2
Given a String str, reverse the string without reversing its individual words. Words are separated by dots.

Note: The last character has not been '.'. 

Examples :

Input: str = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i
Input: str = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole string , the input string becomes mno.pqr
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 <= |str| <= 105
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        vector<string> words;
        stringstream ss(str);
        string word;
        
        // Split the string by dots and store the words in a vector
        while (getline(ss, word, '.')) {
            words.push_back(word);
        }
        
        // Reverse the vector of words
        reverse(words.begin(), words.end());
        
        // Join the reversed words with dots
        string result = words[0];  // First word
        for (int i = 1; i < words.size(); i++) {
            result += "." + words[i];  // Append dot before each subsequent word
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string str = "i.like.this.program.very.much";
    
    // Call the function and print the result
    string result = sol.reverseWords(str);
    cout << result << endl;
    
    return 0;
}
