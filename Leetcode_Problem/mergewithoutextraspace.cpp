/*
Merge Without Extra Space
Difficulty: HardAccuracy: 32.01%Submissions: 268K+Points: 8
Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.

Examples:

Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
Output:
2 2 3 4
7 10
Explanation: After merging the two non-decreasing arrays, we get, 2 2 3 4 7 10
Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]
Output:
1 2 3 5 8 9
10 13 15 20
Explanation: After merging two sorted arrays we get 5 10 12 18 20.
Input: a[] = [0, 1], b[] = [2, 3]
Output:
0 1
2 3
Explanation: After merging two sorted arrays we get 0 1 2 3.
Constraints:
1 <= a.size(), b.size() <= 105
0 <= a[i], b[i] <= 107

*/
public:
    void mergeArrays(std::vector<int>& a, std::vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int i = n - 1, j = 0;

        // Step 1: Compare and swap
        while (i >= 0 && j < m) {
            if (a[i] > b[j]) {
                std::swap(a[i], b[j]);
            }
            i--;
            j++;
        }

        // Step 2: Sort both arrays
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
    }
};