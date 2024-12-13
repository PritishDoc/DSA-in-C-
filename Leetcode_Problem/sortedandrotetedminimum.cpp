/*


Sorted and Rotated Minimum
Difficulty: EasyAccuracy: 40.57%Submissions: 125K+Points: 2
A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. 

Examples:

Input: arr[] = [5, 6, 1, 2, 3, 4]
Output: 1
Explanation: 1 is the minimum element in the array.
Input: arr[] = [3, 1, 2]
Output: 1
Explanation: Here 1 is the minimum element.
Input: arr[] = [4, 2, 3]
Output: 2
Explanation: Here 2 is the minimum element.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 109

*/

#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is greater than the last element,
            // the minimum is in the right half
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            }
            // Otherwise, the minimum is in the left half
            else {
                high = mid;
            }
        }

        // The low pointer points to the minimum element
        return arr[low];
    }
};
