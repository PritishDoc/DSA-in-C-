/*
Number of pairs
Difficulty: MediumAccuracy: 21.82%Submissions: 78K+Points: 4
Given two positive integer arrays arr and brr, find the number of pairs such that xy > yx (raised to power of) where x is an element from arr and y is an element from brr.

Examples :

Input: arr[] = [2, 1, 6], brr[] = [1, 5]
Output: 3
Explanation: The pairs which follow xy > yx are: 21 > 12,  25 > 52 and 61 > 16 .
Input: arr[] = [2 3 4 5], brr[] = [1 2 3]
Output: 5
Explanation: The pairs which follow xy > yx are: 21 > 12 , 31 > 13 , 32 > 23 , 41 > 14 , 51 > 15 .
Expected Time Complexity: O((N + M)log(N)).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ arr.size(), brr.size() ≤ 105
1 ≤ brr[i], arr[i] ≤ 103
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to count elements greater than a given value
    int countGreaterThan(vector<int>& brr, int val) {
        auto it = upper_bound(brr.begin(), brr.end(), val);
        return distance(it, brr.end());
    }

    long long countPairs(vector<int>& arr, vector<int>& brr) {
        sort(brr.begin(), brr.end());
        
        int countOf0 = count(brr.begin(), brr.end(), 0);
        int countOf1 = count(brr.begin(), brr.end(), 1);
        int countOf2 = count(brr.begin(), brr.end(), 2);
        int countOf3 = count(brr.begin(), brr.end(), 3);
        int countOf4 = count(brr.begin(), brr.end(), 4);

        long long totalPairs = 0;

        for (int x : arr) {
            if (x == 0) continue;  // No valid pairs for x = 0

            if (x == 1) {
                totalPairs += countOf0;  // Valid pairs when x = 1 and y = 0
            } else {
                // All elements in brr that are greater than x
                totalPairs += countGreaterThan(brr, x);
                
                // Handle pairs with y = 0 or y = 1
                totalPairs += countOf0 + countOf1;

                if (x == 2) {
                    // Special handling for x = 2, subtract cases with y = 3, 4
                    totalPairs -= countOf3 + countOf4;
                }
                
                if (x == 3) {
                    // Special handling for x = 3, add cases with y = 2
                    totalPairs += countOf2;
                }
            }
        }

        return totalPairs;
    }
};
