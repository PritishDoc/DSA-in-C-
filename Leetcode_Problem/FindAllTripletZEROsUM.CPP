/*
Find All Triplets with Zero Sum
Difficulty: MediumAccuracy: 50.36%Submissions: 41K+Points: 4
Given an array arr[], find all possible triplets i, j, k in the arr[] whose sum of elements is equals to zero. 
Returned triplet should also be internally sorted i.e. i<j<k.

Examples:

Input: arr[] = [0, -1, 2, -3, 1]
Output: [[0, 1, 4], [2, 3, 4]]
Explanation: Triplets with sum 0 are:
arr[0] + arr[1] + arr[4] = 0 + (-1) + 1 = 0
arr[2] + arr[3] + arr[4] = 2 + (-3) + 1 = 0
Input: arr[] = [1, -2, 1, 0, 5]
Output: [[0, 1, 2]]
Explanation: Only triplet which satisfies the condition is arr[0] + arr[1] + arr[2] = 1 + (-2) + 1 = 0
Input: arr[] = [2, 3, 1, 0, 5]
Output: [[]]
Explanation: There is no triplet with sum 0.
Constraints:
3 <= arr.size() <= 103
-104 <= arr[i] <= 104

*/
public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        vector<vector<int>> result;
        int n = arr.size();
        
        // Step 1: Create a map of value to original indices
        vector<pair<int, int>> valueIndex;
        for (int i = 0; i < n; ++i) {
            valueIndex.push_back({arr[i], i});
        }
        sort(valueIndex.begin(), valueIndex.end()); // Sort based on values
        
        // Extract the sorted values and maintain their indices
        vector<int> sortedArr(n);
        vector<int> indices(n);
        for (int i = 0; i < n; ++i) {
            sortedArr[i] = valueIndex[i].first;
            indices[i] = valueIndex[i].second;
        }
        
        // Step 2: Find triplets
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && sortedArr[i] == sortedArr[i - 1]) continue; // Skip duplicates for the first element
            
            int target = -sortedArr[i];
            int left = i + 1, right = n - 1;
            
            while (left < right) {
                int sum = sortedArr[left] + sortedArr[right];
                if (sum == target) {
                    vector<int> triplet = {indices[i], indices[left], indices[right]};
                    sort(triplet.begin(), triplet.end()); // Sort indices to maintain lexicographical order
                    result.push_back(triplet);
                    
                    // Move pointers and skip duplicates
                    while (left < right && sortedArr[left] == sortedArr[left + 1]) ++left;
                    while (left < right && sortedArr[right] == sortedArr[right - 1]) --right;
                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        // Step 3: Remove duplicates from the result
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        
        return result;
    }
};