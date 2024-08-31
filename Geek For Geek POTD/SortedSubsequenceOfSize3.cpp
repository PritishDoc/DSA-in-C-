/*

Sorted subsequence of size 3
Difficulty: MediumAccuracy: 25.95%Submissions: 68K+Points: 4
You are given an array arr, you need to find any three elements in it such that arr[i] < arr[j] < arr[k] and i < j < k.

Note:

The output will be 1 if the subsequence returned by the function is present in the array arr
If the subsequence is not present in the array then return an empty array, the driver code will print 0.
If the subsequence returned by the function is not in the format as mentioned then the output will be -1.
Examples :

Input: arr = [1, 2, 1, 1, 3]
Output: 1
Explanation: A subsequence 1 2 3 exist.
Input: arr = [1, 1, 3]
Output: 0
Explanation: No such Subsequence exist, so empty array is returned (the driver code automatically prints 0 in this case).
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 106

*/
class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return {}; // Return an empty array if the size is less than 3

        // Arrays to store the smallest and largest elements on left and right of each element
        vector<int> smallest(n), largest(n);

        // Fill the smallest array, smallest[i] will hold the smallest value till index i
        smallest[0] = arr[0];
        for (int i = 1; i < n; i++) {
            smallest[i] = min(smallest[i - 1], arr[i]);
        }

        // Fill the largest array, largest[i] will hold the largest value from index i till the end
        largest[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            largest[i] = max(largest[i + 1], arr[i]);
        }

        // Find the subsequence
        for (int j = 1; j < n - 1; j++) {
            if (arr[j] > smallest[j - 1] && arr[j] < largest[j + 1]) {
                return {smallest[j - 1], arr[j], largest[j + 1]};
            }
        }

        // If no such triplet is found
        return {};
    }
};