/*
 Minimum Time Difference
Medium
Topics

Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 

Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".
*/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Convert each time to minutes since midnight
        vector<int> minutes;
        for (const string& time : timePoints) {
            int hours = stoi(time.substr(0, 2));
            int mins = stoi(time.substr(3, 2));
            minutes.push_back(hours * 60 + mins);
        }
        
        // Sort the time points
        sort(minutes.begin(), minutes.end());
        
        // Initialize the minimum difference to a large number
        int minDiff = INT_MAX;
        
        // Compare consecutive times and calculate their difference
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        // Special case: Compare the first and last time points (wrap-around case)
        int wrapAroundDiff = (1440 - minutes.back()) + minutes.front();
        minDiff = min(minDiff, wrapAroundDiff);
        
        return minDiff;
    }
};
