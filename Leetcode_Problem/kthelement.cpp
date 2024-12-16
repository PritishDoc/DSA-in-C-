/*

K-th element of two Arrays
Difficulty: MediumAccuracy: 37.4%Submissions: 288K+Points: 4
Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
Input: a[] = [100, 112, 256, 349, 770], b[] = [72, 86, 113, 119, 265, 445, 892], k = 7
Output: 256
Explanation: Combined sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.
Constraints:

1 <= a.size(), b.size() <= 106
1 <= k <= a.size() + b.size()
0 <= a[i], b[i] < 108

*/
public:
    int kthElement(std::vector<int>& a, std::vector<int>& b, int k) {
        if (a.size() > b.size()) {
            return kthElement(b, a, k); // Ensure 'a' is the smaller array
        }
        
        int n = a.size();
        int m = b.size();
        int low = std::max(0, k - m);  // Minimum possible partition in `a`
        int high = std::min(k, n);    // Maximum possible partition in `a`
        
        while (low <= high) {
            int i = (low + high) / 2;   // Partition index for `a`
            int j = k - i;             // Partition index for `b`
            
            // Boundary conditions
            int aLeft = (i > 0) ? a[i - 1] : INT_MIN;
            int aRight = (i < n) ? a[i] : INT_MAX;
            int bLeft = (j > 0) ? b[j - 1] : INT_MIN;
            int bRight = (j < m) ? b[j] : INT_MAX;
            
            // Valid partition
            if (aLeft <= bRight && bLeft <= aRight) {
                return std::max(aLeft, bLeft);
            }
            // Adjust the binary search range
            else if (aLeft > bRight) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        
        return -1; // This case will never occur due to problem constraints
    }
};