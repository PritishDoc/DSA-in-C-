/*
Best Sightseeing Pair
Hint
You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

 

Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
Example 2:

Input: values = [1,2]
Output: 2
 

Constraints:

2 <= values.length <= 5 * 104
1 <= values[i] <= 1000
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int max_i = values[0]; // Maximum value of values[i] + i seen so far

        for (int j = 1; j < values.size(); ++j) {
            // Calculate the score for the current pair
            maxScore = max(maxScore, max_i + values[j] - j);
            // Update max_i for the next iteration
            max_i = max(max_i, values[j] + j);
        }

        return maxScore;
    }
};
