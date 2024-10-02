/*
Rotate and delete
Difficulty: MediumAccuracy: 20.63%Submissions: 48K+Points: 4
Given an array arr integers. Assume sz to be the initial size of the array. Do the following operations exactly sz/2 times. In every kth (1<= k <= sz/2) operation:

Right-rotate the array clockwise by 1.
Delete the (n– k + 1)th element from begin.
Now, Return the first element of the array.
Note: Here n keeps on decreasing with every operation.

Examples:

Input: arr = [1, 2, 3, 4, 5, 6]
Output: 3
Explanation: Rotate the array clockwise i.e. after rotation the array arr = [6, 1, 2, 3, 4, 5] and delete the last element that is 5 that will be arr = [6, 1, 2, 3, 4]. Again rotate the array for the second time and deletes the second last element that is 2 that will be A = [4, 6, 1, 3], doing similar operation when we perform 4th operation, 4th last element does not exist. Then we deletes 1st element ie 1 that will be arr = [3, 6]. So, continuing this procedure the last element in arr is 2. So, the output will be 3.
Input: arr = [1, 2, 3, 4]
Output: 2
Explanation: Rotate the vector clockwise i.e. after rotation the vector arr = [4, 1, 2, 3] and delete the last element that is 3 that will be arr = [4, 1, 2]. After doing all the operations, the output will be 2.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 103
*/

class Solution {
public:
    int rotateDelete(vector<int> &arr) {
        int n = arr.size();
        
        // Perform sz/2 operations
        for (int k = 1; k <= n / 2; ++k) {
            // Rotate array clockwise by one (right-rotation)
            int lastElement = arr.back();  // Store the last element
            arr.pop_back();                // Remove the last element
            arr.insert(arr.begin(), lastElement);  // Insert the last element at the front
            
            // Calculate the (n-k+1)-th element to delete
            int indexToDelete = arr.size() - k;  // Adjusting the 1-based index to 0-based
            
            // Delete the element at the calculated index
            arr.erase(arr.begin() + indexToDelete);
        }
        
        // Return the first element after all operations
        return arr[0];
    }
};
