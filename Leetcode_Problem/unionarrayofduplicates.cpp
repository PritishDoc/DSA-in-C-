/*
Union of Arrays with Duplicates
Difficulty: EasyAccuracy: 42.22%Submissions: 402K+Points: 2
Given two arrays a[] and b[], the task is to find the number of elements in the union between these two arrays.

The Union of the two arrays can be defined as the set containing distinct elements from both arrays. If there are repetitions, then only one element occurrence should be there in the union.

Note: Elements of a[] and b[] are not necessarily distinct.

Examples

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3]
Output: 5
Explanation: Union set of both the arrays will be 1, 2, 3, 4 and 5. So count is 5.
Input: a[] = [85, 25, 1, 32, 54, 6], b[] = [85, 2] 
Output: 7
Explanation: Union set of both the arrays will be 85, 25, 1, 32, 54, 6, and 2. So count is 7.
Input: a[] = [1, 2, 1, 1, 2], b[] = [2, 2, 1, 2, 1] 
Output: 2
Explanation: We need to consider only distinct. So count of elements in union set will be 2.
Constraints:
1 ≤ a.size(), b.size() ≤ 106
0 ≤ a[i], b[i] ≤ 10
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the count of number of elements in the union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // Using an unordered_set to store distinct elements.
        unordered_set<int> unionSet;

        // Insert all elements of the first array into the set.
        for (int num : a) {
            unionSet.insert(num);
        }

        // Insert all elements of the second array into the set.
        for (int num : b) {
            unionSet.insert(num);
        }

        // The size of the set gives the count of distinct elements.
        return unionSet.size();
    }
};

// Driver code to test the function
int main() {
    Solution solution;
    vector<int> a = {85, 25, 1, 32, 54, 6};
    vector<int> b = {85, 2};
    
    cout << "Count of union: " << solution.findUnion(a, b) << endl;
    return 0;
}
