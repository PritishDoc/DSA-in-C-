/*
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
 

Constraints:

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.
*/


//code..........

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Step 1: Create a vector of pairs
        vector<pair<int, string>> people;
        int n = names.size();
        
        for (int i = 0; i < n; ++i) {
            people.push_back({heights[i], names[i]});
        }
        
        // Step 2: Sort the vector of pairs by heights in descending order
        sort(people.begin(), people.end(), [](pair<int, string>& a, pair<int, string>& b) {
            return a.first > b.first;
        });
        
        // Step 3: Extract the names in the sorted order
        vector<string> sorted_names;
        for (const auto& p : people) {
            sorted_names.push_back(p.second);
        }
        
        return sorted_names;
    }
};
