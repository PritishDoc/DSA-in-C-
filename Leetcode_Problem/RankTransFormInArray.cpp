/*
Rank Transform of an Array

Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.
 

Example 1:

Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
Example 2:

Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.
Example 3:

Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
 

Constraints:

0 <= arr.length <= 105
-109 <= arr[i] <= 109

*/
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};  // Edge case: if the input array is empty
        
        vector<int> sortedArr = arr;  // Create a copy of the input array
        sort(sortedArr.begin(), sortedArr.end());  // Sort the copied array
        
        // Create a map to store the rank of each element
        unordered_map<int, int> rankMap;
        int rank = 1;
        
        // Assign ranks to the unique elements
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }
        
        // Replace each element in the original array with its rank
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = rankMap[arr[i]];
        }
        
        return arr;
    }
};