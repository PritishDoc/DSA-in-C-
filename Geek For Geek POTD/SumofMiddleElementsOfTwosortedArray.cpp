/*
Sum of Middle elements of two sorted arrays
Difficulty: MediumAccuracy: 47.98%Submissions: 67K+Points: 4
Given 2 sorted integer arrays arr1 and arr2. Find the sum of the middle elements of two sorted arrays arr1 and arr2.

Examples:

Input: arr1 = [1, 2, 4, 6, 10], arr2 = [4, 5, 6, 9, 12]
Output: 11
Explanation: The merged array looks like [1, 2, 4, 4, 5, 6, 6, 9, 10, 12]. Sum of middle elements is 11 (5 + 6).
Input: arr1 = [1, 12, 15, 26, 38], arr2 = [2, 13, 17, 30, 45]
Output: 32
Explanation: The merged array looks like [1, 2, 12, 13, 15, 17, 26, 30, 38, 45]. Sum of middle elements is 32 (15 + 17).
Expected Time Complexity: O(log n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr1.size() == arr2.size() <= 103
1 <= arr1[i] <= 106
1 <= arr2[i] <= 106
*/

public:
    int SumofMiddleElements(std::vector<int> &arr1, std::vector<int> &arr2) {
        int n = arr1.size();
        
        // Ensure arr1 is the smaller array
        if (n == 0) return 0;
        if (arr1[0] > arr2[0]) std::swap(arr1, arr2);
        
        int low = 0, high = n;
        
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = n - cut1;
            
            int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            
            int right1 = (cut1 == n) ? INT_MAX : arr1[cut1];
            int right2 = (cut2 == n) ? INT_MAX : arr2[cut2];
            
            if (left1 <= right2 && left2 <= right1) {
                // Found the partition
                return std::max(left1, left2) + std::min(right1, right2);
            } else if (left1 > right2) {
                // We are too far right on arr1, move left
                high = cut1 - 1;
            } else {
                // We are too far left on arr1, move right
                low = cut1 + 1;
            }
        }
        
        return 0;
    }
};