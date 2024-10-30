/*
Pairs with difference k
Difficulty: EasyAccuracy: 22.41%Submissions: 37K+Points: 2
Given an array arr[] of positive integers. Find the number of pairs of integers whose difference equals a given number k.
Note: (a, b) and (b, a) are considered the same. Also, the same numbers at different indices are considered different.

Examples:

Input: arr[] = [1, 5, 3, 4, 2], k = 3
Output: 2
Explanation: There are 2 pairs with difference 3,the pairs are {1, 4} and {5, 2} 
Input: arr[] = [8, 12, 16, 4, 0, 20], k = 4
Output: 5
Explanation: There are 5 pairs with difference 4, the pairs are {0, 4}, {4, 8}, {8, 12}, {12, 16} and {16, 20}.
Constraints:
1 <= arr.size() <= 106
1 <= k <= 106
0 <= arr[i] <= 106

*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_map<int, int> freqMap;
        int count = 0;

        // Fill the frequency map with each element's frequency
        for (int num : arr) {
            freqMap[num]++;
        }

        // Count pairs with difference k
        for (auto it = freqMap.begin(); it != freqMap.end(); ++it) {
            int num = it->first;
            int freq = it->second;
            
            if (freqMap.count(num + k)) {
                count += freq * freqMap[num + k];
            }
        }

        return count;
    }
};
