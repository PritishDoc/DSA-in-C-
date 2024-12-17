/*
Aggressive Cows
Difficulty: MediumAccuracy: 59.57%Submissions: 94K+Points: 4
You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples :

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.
Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.
Constraints:
2 <= stalls.size() <= 106
0 <= stalls[i] <= 108
1 <= k <= stalls.size()

*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to check if we can place cows with at least 'distance' apart
    bool canPlaceCows(vector<int> &stalls, int k, int distance) {
        int cowsPlaced = 1; // Place the first cow in the first stall
        int lastPosition = stalls[0];
        
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPosition >= distance) {
                cowsPlaced++;
                lastPosition = stalls[i]; // Place the cow at this stall
                if (cowsPlaced == k) return true; // All cows are placed
            }
        }
        return false; // Cannot place all cows
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        // Step 1: Sort the stalls
        sort(stalls.begin(), stalls.end());
        
        // Step 2: Initialize binary search range
        int low = 1; // Minimum possible distance
        int high = stalls.back() - stalls.front(); // Maximum possible distance
        int result = 0;
        
        // Step 3: Binary search on distance
        while (low <= high) {
            int mid = low + (high - low) / 2; // Mid-point of the distance range
            
            if (canPlaceCows(stalls, k, mid)) {
                result = mid;    // Update result with the valid distance
                low = mid + 1;   // Try for a larger distance
            } else {
                high = mid - 1;  // Reduce the distance
            }
        }
        
        return result; // Return the largest valid minimum distance
    }
};
