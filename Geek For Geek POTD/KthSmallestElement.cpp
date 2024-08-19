/*

Kth Smallest
Difficulty: MediumAccuracy: 35.17%Submissions: 624K+Points: 4
Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array. It is given that all array elements are distinct.

Follow up: Don't solve it using the inbuilt sort function.

Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output:  7
Explanation: 3rd smallest element in the given array is 7.
Input: arr[] = [7, 10, 4, 20, 15], k = 4 
Output:  15
Explanation: 4th smallest element in the given array is 15.
Expected Time Complexity: O(n+(max_element) )
Expected Auxiliary Space: O(max_element)
Constraints:
1 <= arr.size <= 106
1<= arr[i] <= 106
1 <= k <= n
*/



#include <vector>
#include <algorithm>

class Solution {
public:
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high];  // Choose the last element as pivot
        int i = low;  // Index of smaller element
        
        for (int j = low; j < high; ++j) {
            if (arr[j] <= pivot) {
                std::swap(arr[i], arr[j]);
                i++;
            }
        }
        std::swap(arr[i], arr[high]);
        return i;  // Return the partition index
    }
    
    int quickSelect(std::vector<int>& arr, int low, int high, int k) {
        if (low <= high) {
            int pi = partition(arr, low, high);
            
            if (pi == k - 1) {
                return arr[pi];  // k-th smallest element found
            } else if (pi > k - 1) {
                return quickSelect(arr, low, pi - 1, k);
            } else {
                return quickSelect(arr, pi + 1, high, k);
            }
        }
        return -1;  // If something goes wrong (though it shouldn't)
    }
    
    int kthSmallest(std::vector<int>& arr, int k) {
        int n = arr.size();
        return quickSelect(arr, 0, n - 1, k);
    }
};
