/*
Nearly sorted
Difficulty: MediumAccuracy: 75.25%Submissions: 60K+Points: 4
Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.
Note: You need to change the given array arr[] in place.

Examples:

Input: arr[] = [6, 5, 3, 2, 8, 10, 9], k = 3
Output: [2, 3, 5, 6, 8, 9, 10]
Explanation: The sorted array will be 2 3 5 6 8 9 10
Input: arr[]= [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: The sorted array will be 1 2 3 4 5 6 7 8 9 10
DO NOT use the direct library sort() function for this question.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ k < arr.size()
1 ≤ arri ≤ 106

*/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    void nearlySorted(vector<int>& arr, int k) {
        // Min-heap to hold the smallest elements within the range
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Step 1: Insert the first k+1 elements into the min-heap
        for (int i = 0; i <= k && i < arr.size(); i++) {
            minHeap.push(arr[i]);
        }

        int index = 0;  // To keep track of the index in the sorted array

        // Step 2: Process the rest of the elements
        for (int i = k + 1; i < arr.size(); i++) {
            arr[index++] = minHeap.top();
            minHeap.pop();
            minHeap.push(arr[i]);
        }

        // Step 3: Empty the remaining elements in the min-heap
        while (!minHeap.empty()) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {6, 5, 3, 2, 8, 10, 9};
    int k1 = 3;
    sol.nearlySorted(arr1, k1);
    for (int num : arr1) cout << num << " ";
    cout << endl;

    vector<int> arr2 = {1, 4, 5, 2, 3, 6, 7, 8, 9, 10};
    int k2 = 2;
    sol.nearlySorted(arr2, k2);
    for (int num : arr2) cout << num << " ";
    cout << endl;

    return 0;
}
