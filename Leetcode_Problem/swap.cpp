/*
Two Swaps
Difficulty: EasyAccuracy: 49.85%Submissions: 27K+Points: 2
Given a permutation of some of the first natural numbers in an array arr[], determine if the array can be sorted in exactly two swaps. A swap can involve the same pair of indices twice.

Return true if it is possible to sort the array with exactly two swaps, otherwise return false.

Examples:

Input: arr = [4, 3, 2, 1]
Output: true
Explanation: First, swap arr[0] and arr[3]. The array becomes [1, 3, 2, 4]. Then, swap arr[1] and arr[2]. The array becomes [1, 2, 3, 4], which is sorted.
Input: arr = [4, 3, 1, 2]
Output: false
Explanation: It is not possible to sort the array with exactly two swaps.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ arr.size()
*/
#include <vector>
#include <algorithm>

class Solution {
public:
    bool checkSorted(std::vector<int> &arr) {
        // Get a sorted version of the array
        std::vector<int> sortedArr = arr;
        std::sort(sortedArr.begin(), sortedArr.end());

        // Find the indices where the array is not sorted
        std::vector<int> misplacedIndices;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] != sortedArr[i]) {
                misplacedIndices.push_back(i);
            }
        }

        // If no elements are misplaced, the array is already sorted
        if (misplacedIndices.size() == 0) return true;

        // If there are more than 4 misplaced elements, we cannot sort with exactly two swaps
        if (misplacedIndices.size() > 4) return false;

        // If there are exactly 2 misplaced elements, one swap can sort it
        if (misplacedIndices.size() == 2) {
            // Swap the two misplaced elements and check if the array gets sorted
            std::swap(arr[misplacedIndices[0]], arr[misplacedIndices[1]]);
            return arr == sortedArr;
        }

        // If there are exactly 4 misplaced elements, try two swaps to sort the array
        if (misplacedIndices.size() == 4) {
            // First swap between the first pair of misplaced elements
            std::swap(arr[misplacedIndices[0]], arr[misplacedIndices[1]]);
            // Then swap between the second pair of misplaced elements
            std::swap(arr[misplacedIndices[2]], arr[misplacedIndices[3]]);
            return arr == sortedArr;
        }

        return false;
    }
};
