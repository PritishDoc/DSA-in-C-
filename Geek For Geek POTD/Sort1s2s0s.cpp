/*
Sort 0s, 1s and 2s
Difficulty: EasyAccuracy: 50.58%Submissions: 690K+Points: 2
Given an array arr containing only 0s, 1s, and 2s. Sort the array in ascending order.

Examples:

Input: arr[]= [0, 2, 1, 2, 0]
Output: 0 0 1 2 2
Explanation: 0s 1s and 2s are segregated into ascending order.
Input: arr[] = [0, 1, 0]
Output: 0 0 1
Explanation: 0s 1s and 2s are segregated into ascending order.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 106
0 <= arr[i] <= 2
*/
#include <vector>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int l = 0, m = 0, h = arr.size() - 1;
        
        // Traverse through the array
        while (m <= h) {
            if (arr[m] == 0) {
                swap(arr[l], arr[m]);
                l++;
                m++;
            } else if (arr[m] == 1) {
                m++;
            } else {
                swap(arr[m], arr[h]);
                h--;
            }
        }
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> arr = {0, 2, 1, 2, 0};
    sol.sort012(arr);
    for(int i : arr) {
        cout << i << " ";
    }
    return 0;
}
