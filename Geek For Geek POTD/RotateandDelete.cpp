/*

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
            
            // Delete the (n-k+1)th element from the start (1-based index)
            int indexToDelete = n - k;  // (n-k+1) - 1 = n-k (0-based index)
            arr.erase(arr.begin() + indexToDelete);  // Remove the element
            
            // Decrease the size of the array
            n--;
        }
        
        // After the operations, return the first element
        return arr[0];
    }
};
*/