/*
Find All Triplets with Zero Sum
Difficulty: MediumAccuracy: 50.36%Submissions: 41K+Points: 4
Given an array arr[], find all possible triplets i, j, k in the arr[] whose sum of elements is equals to zero. 
Returned triplet should also be internally sorted i.e. i<j<k.

Examples:

Input: arr[] = [0, -1, 2, -3, 1]
Output: [[0, 1, 4], [2, 3, 4]]
Explanation: Triplets with sum 0 are:
arr[0] + arr[1] + arr[4] = 0 + (-1) + 1 = 0
arr[2] + arr[3] + arr[4] = 2 + (-3) + 1 = 0
Input: arr[] = [1, -2, 1, 0, 5]
Output: [[0, 1, 2]]
Explanation: Only triplet which satisfies the condition is arr[0] + arr[1] + arr[2] = 1 + (-2) + 1 = 0
Input: arr[] = [2, 3, 1, 0, 5]
Output: [[]]
Explanation: There is no triplet with sum 0.
Constraints:
3 <= arr.size() <= 103
-104 <= arr[i] <= 104

*/
// User function Template for C++class Solution {
  class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Set to handle duplicates
        set<vector<int>> resSet;
        int n = arr.size();
        unordered_map<int, vector<pair<int, int>>> mp;

        // Store sum of all the pairs with their indices
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                mp[arr[i] + arr[j]].push_back({i, j});
        }

        for (int i = 0; i < n; i++) {

            // Find remaining value to get zero sum
            int rem = -arr[i];
            if (mp.find(rem) != mp.end()) {
                vector<pair<int, int>> pairs = mp[rem];
                for (auto p : pairs) {

                    // Ensure no two indices are same in triplet
                    if (p.first != i && p.second != i) {
                        vector<int> curr = {i, p.first, p.second};
                        sort(curr.begin(), curr.end());
                        resSet.insert(curr);
                    }
                }
            }
        }

        vector<vector<int>> res(resSet.begin(), resSet.end());
        return res;
    }
};