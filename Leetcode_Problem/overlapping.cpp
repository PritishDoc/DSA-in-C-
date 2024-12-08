/*

Overlapping Intervals
Difficulty: MediumAccuracy: 57.41%Submissions: 85K+Points: 4
Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

Examples:

Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
Output: [[1,4], [6,8], [9,10]]
Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].
Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
Output: [[1,9]]
Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Sort intervals based on the start time
        sort(arr.begin(), arr.end());

        vector<vector<int>> merged;

        for (const auto& interval : arr) {
            // If the merged list is empty or the current interval does not overlap
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // Overlapping intervals, merge them by updating the end time
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }

    Solution obj;
    vector<vector<int>> ans = obj.mergeOverlap(arr);

    for (const auto& interval : ans) {
        cout << interval[0] << " " << interval[1] << endl;
    }

    return 0;
}
