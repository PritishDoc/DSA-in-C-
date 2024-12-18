/*
Allocate Minimum Pages
Difficulty: MediumAccuracy: 35.51%Submissions: 229K+Points: 4
You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
[12] and [34, 67, 90] Maximum Pages = 191
[12, 34] and [67, 90] Maximum Pages = 157
[12, 34, 67] and [90] Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Allocation can not be done.
Input: arr[] = [22, 23, 67], k = 1
Output: 112
Constraints:
1 <=  arr.size() <= 106
1 <= arr[i] <= 103
1 <= k <= 103 

*/

#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to check if it's possible to allocate books such that the max pages is <= mid
    bool isPossible(vector<int>& arr, int n, int k, int mid) {
        int studentCount = 1; // Start with one student
        int currentPages = 0;

        for (int i = 0; i < n; ++i) {
            if (arr[i] > mid) return false; // A single book has more pages than mid, not possible

            if (currentPages + arr[i] > mid) {
                // Assign current book to the next student
                studentCount++;
                currentPages = arr[i];

                // If the number of students exceeds k, return false
                if (studentCount > k) return false;
            } else {
                currentPages += arr[i];
            }
        }

        return true;
    }

    // Function to find the minimum of the maximum pages
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n) return -1; // More students than books, not possible

        int low = *max_element(arr.begin(), arr.end()); // Minimum possible max pages
        int high = accumulate(arr.begin(), arr.end(), 0); // Maximum possible max pages
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, n, k, mid)) {
                result = mid; // Update result and try for a smaller max
                high = mid - 1;
            } else {
                low = mid + 1; // Try for a larger max
            }
        }

        return result;
    }
};
``
