class Solution {
public:
    int totalCount(int k, vector<int>& arr) {
        // Initialize total count to 0
        long long total = 0;

        // Iterate through each number in the array
        for(auto num : arr){
            // If the number is 0, it doesn't contribute to the count
            if(num == 0){
                continue;
            }

            // Compute the number of parts using ceiling division
            // (num + k - 1) / k ensures ceiling without using floating point
            total += (num + k - 1) / k;
        }

        // Since the function is expected to return an int, cast the result
        // It's assumed that the total will fit within the integer range based on problem constraints
        return static_cast<int>(total);
    }
};