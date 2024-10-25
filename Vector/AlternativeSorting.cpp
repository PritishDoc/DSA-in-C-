/*
Alternative Sorting
Difficulty: BasicAccuracy: 50.2%Submissions: 30K+Points: 1
Given an array arr of distinct integers. Rearrange the array in such a way that the first element is the largest and the second element is the smallest, the third element is the second largest and the fourth element is the second smallest, and so on.

Examples:

Input: arr[] = [7, 1, 2, 3, 4, 5, 6]
Output: [7, 1, 6, 2, 5, 3, 4]
Explanation: The first element is first maximum and second element is first minimum and so on.
Input: arr[] = [1, 6, 9, 4, 3, 7, 8, 2]
Output: [9, 1, 8, 2, 7, 3, 6, 4]
Explanation: The first element is first maximum and second element is first minimum and so on.
Expected Time Complexity: O(nlogn).
Expected Auxiliary Space: O(n).

Constraints:
1 ≤ arr.size() ≤ 105

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//[1, 2, 3, 6, 7, 8, 9]
class Solution {
public:
    vector<int> alternateSort(vector<int>& arr) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        vector<int> result;
        int left = 0, right = arr.size() - 1;

        // Step 2: Use two-pointer approach to add largest and smallest elements alternately
        while (left <= right) {
            // Add largest remaining element
            if (left != right) {
                result.push_back(arr[right--]);
            }
            // Add smallest remaining element
            result.push_back(arr[left++]);
        }

        return result;
    }
};

int main() {
    Solution solution;
    int n;

    // Input: size of the array
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    // Input: elements of the array
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function
    vector<int> result = solution.alternateSort(arr);

    // Output the result
    cout << "Rearranged array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
