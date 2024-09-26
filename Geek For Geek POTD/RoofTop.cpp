/*
class Solution {
public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        int maxSteps = 0;      // To store the maximum consecutive steps
        int currentSteps = 0;  // To store the current consecutive steps

        // Iterate through the array of buildings
        for (int i = 1; i < arr.size(); i++) {
            // Check if the next building is higher than the current one
            if (arr[i] > arr[i - 1]) {
                currentSteps++;  // Increase current step count
            } else {
                currentSteps = 0;  // Reset current steps if no altitude gain
            }
            // Update the maximum steps encountered
            maxSteps = max(maxSteps, currentSteps);
        }
        
        return maxSteps;
    }
};
*/