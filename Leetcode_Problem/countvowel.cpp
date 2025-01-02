/*
Count Vowel Strings in Ranges
Hint
You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].
Example 2:

Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].
 

Constraints:

1 <= words.length <= 105
1 <= words[i].length <= 40
words[i] consists only of lowercase English letters.
sum(words[i].length) <= 3 * 105
1 <= queries.length <= 105
0 <= li <= ri < words.length

*/
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // Set of vowels for quick lookup
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        // Helper function to check if a word starts and ends with a vowel
        auto isVowelString = [&](const string& word) {
            return vowels.count(word.front()) && vowels.count(word.back());
        };

        int n = words.size();
        vector<int> prefix(n, 0);

        // Build prefix sum array
        for (int i = 0; i < n; ++i) {
            prefix[i] = (i > 0 ? prefix[i - 1] : 0) + (isVowelString(words[i]) ? 1 : 0);
        }

        // Process each query
        vector<int> result;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            int count = prefix[r] - (l > 0 ? prefix[l - 1] : 0);
            result.push_back(count);
        }

        return result;
    }
};
