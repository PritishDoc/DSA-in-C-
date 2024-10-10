/*

Max distance between same elements
Difficulty: EasyAccuracy: 46.67%Submissions: 62K+Points: 2
Given an array arr[] with repeated elements, the task is to find the maximum distance between two occurrences of an element.

Note: You may assume that every input array has repetitions.

Examples:

Input: arr = [1, 1, 2, 2, 2, 1]
Output: 5
Explanation: distance for 1 is: 5-0 = 5, distance for 2 is : 4-2 = 2, So max distance is 5.
Input: arr = [3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2]
Output: 10
Explanation: maximum distance for 2 is 11-1 = 10, maximum distance for 1 is 4-2 = 2 ,maximum distance for 4 is 10-5 = 5, So max distance is 10.
Expected Time Complexity :  O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 <= arr.size() <= 106
1 <= arr[i] <= 109
*/

class Solution {
public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> firstOccurrence;  // Stores the first occurrence index of each element
        int maxDist = 0;  // Stores the maximum distance

        for (int i = 0; i < arr.size(); i++) {
            if (firstOccurrence.find(arr[i]) == firstOccurrence.end()) {
                // If this is the first time we've seen this element, store its index
                firstOccurrence[arr[i]] = i;
            } else {
                // If we've seen this element before, calculate the distance
                int dist = i - firstOccurrence[arr[i]];
                maxDist = max(maxDist, dist);  // Update the max distance if this is larger
            }
        }

        return maxDist;
    }
};