/*


Swap and Maximize
Difficulty: EasyAccuracy: 64.35%Submissions: 41K+Points: 2
Given an array arr[ ] of positive elements. Consider the array as a circular array, meaning the element after the last element is the first element of the array. The task is to find the maximum sum of the absolute differences between consecutive elements with shuffling of array elements allowed i.e. shuffle the array elements and make [a1..an] such order that  |a1 – a2| + |a2 – a3| + …… + |an-1 – an| + |an – a1| is maximized.

Examples:

Input: arr[] = [4, 2, 1, 8]
Output: 18
Explanation: After Shuffling, we get [1, 8, 2, 4]. Sum of absolute difference between consecutive elements after rearrangement = |1 - 8| + |8 - 2| + |2 - 4| + |4 - 1| = 7 + 6 + 2 + 3 = 18.
Input: arr[] = [10, 12]
Output: 4
Explanation: No need of rearrangement. Sum of absolute difference between consecutive elements = |10 - 12| + |12 - 10| = 2 + 2 = 4.
Constraints:
2 ≤ arr.size()≤ 105
1 <= arr[i] <= 105
*/
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        // Step 2: Arrange elements in an alternate max-min order
        int n = arr.size();
        vector<int> result;
        int i = 0, j = n - 1;
        
        while (i <= j) {
            if (i == j) {
                result.push_back(arr[i]);
            } else {
                result.push_back(arr[i]);
                result.push_back(arr[j]);
            }
            i++;
            j--;
        }

        // Step 3: Calculate the sum of absolute differences in a circular way
        long long max_sum = 0;
        for (int k = 1; k < n; k++) {
            max_sum += abs(result[k] - result[k - 1]);
        }
        // Circular difference between the last and first element
        max_sum += abs(result[0] - result[n - 1]);

        return max_sum;
    }
};
