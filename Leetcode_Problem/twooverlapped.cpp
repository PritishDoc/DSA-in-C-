/*
Two Best Non-Overlapping Events

Hint
You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

 

Example 1:


Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
Example 2:

Example 1 Diagram
Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.
Example 3:


Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
 

Constraints:

2 <= events.length <= 105
events[i].length == 3
1 <= startTimei <= endTimei <= 109
1 <= valuei <= 106

*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events by endTime
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> maxValue(n, 0);
        maxValue[0] = events[0][2]; // The value of the first event

        // Populate maxValue array
        for (int i = 1; i < n; ++i) {
            maxValue[i] = max(maxValue[i - 1], events[i][2]);
        }

        int result = 0;

        // Iterate through each event
        for (int i = 0; i < n; ++i) {
            // Add the value of the current event
            int currentValue = events[i][2];

            // Find the last event that ends before this one starts
            int left = 0, right = i - 1, idx = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][1] < events[i][0]) {
                    idx = mid; // Found a valid event
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            // Add the value of the best compatible event
            if (idx != -1) {
                currentValue += maxValue[idx];
            }

            // Update the result
            result = max(result, currentValue);
        }

        return result;
    }
};
