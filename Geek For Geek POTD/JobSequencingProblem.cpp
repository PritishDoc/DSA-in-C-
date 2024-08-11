/*
Job Sequencing Problem
Difficulty: MediumAccuracy: 34.51%Submissions: 237K+Points: 4
Given a set of n jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with a job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time on or before which job needs to be completed to earn the profit.

Examples :

Input: Jobs = [[1,4,20],[2,1,1],[3,1,40],[4,1,30]]
Output: 2 60
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
Input: Jobs = [[1,2,100],[2,1,19],[3,2,27],[4,1,25],[5,1,15]]
Output: 2 127
Explanation: 2 jobs can be done with maximum profit of 127 (100+27).
Expected Time Complexity: O(nlogn)
Expected Auxilliary Space: O(n)

Constraints:
1 <= n <= 105
1 <= Deadline,id <= n
1 <= Profit <= 500
*/
class Solution 
{
    public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // Step 1: Sort the jobs by profit in descending order
        sort(arr, arr + n, [](Job a, Job b) {
            return a.profit > b.profit;
        });
        
        // Step 2: Find the maximum deadline to size the time slots
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        // Step 3: Create a schedule array to track filled time slots
        vector<int> schedule(maxDeadline + 1, -1);
        
        int jobCount = 0;  // Count of jobs done
        int totalProfit = 0; // Total profit earned
        
        // Step 4: Schedule the jobs
        for (int i = 0; i < n; i++) {
            // Try to schedule the job at the latest possible slot before its deadline
            for (int j = arr[i].dead; j > 0; j--) {
                if (schedule[j] == -1) { // If the slot is available
                    schedule[j] = arr[i].id; // Mark this time slot as filled
                    jobCount++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        
        return {jobCount, totalProfit}; // Return the number of jobs done and total profit
    } 
};