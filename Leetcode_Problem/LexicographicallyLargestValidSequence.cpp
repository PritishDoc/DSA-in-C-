/*
Construct the Lexicographically Largest Valid Sequence
Medium
Topics
Companies
Hint
Given an integer n, find a sequence that satisfies all of the following:

The integer 1 occurs once in the sequence.
Each integer between 2 and n occurs twice in the sequence.
For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

 

Example 1:

Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
Example 2:

Input: n = 5
Output: [5,3,1,4,3,5,2,4,2]
 

Constraints:

1 <= n <= 20


*/
class Solution {
    public int[] constructDistancedSequence(int n) {
        int len = 2 * n - 1;
        int[] result = new int[len];
        boolean[] used = new boolean[n + 1]; // To track which numbers are used
        backtrack(result, used, 0, n);
        return result;
    }

    private boolean backtrack(int[] result, boolean[] used, int index, int n) {
        // If we have filled the array, return true
        if (index == result.length) return true;

        // If this position is already filled, move to the next
        if (result[index] != 0) return backtrack(result, used, index + 1, n);

        // Try placing the largest number first
        for (int num = n; num >= 1; num--) {
            if (!used[num]) {
                // If num == 1, it occupies only one position
                if (num == 1) {
                    result[index] = 1;
                    used[1] = true;
                    if (backtrack(result, used, index + 1, n)) return true;
                    used[1] = false;
                    result[index] = 0;
                } 
                // If num > 1, it needs two positions
                else if (index + num < result.length && result[index + num] == 0) {
                    result[index] = result[index + num] = num;
                    used[num] = true;
                    if (backtrack(result, used, index + 1, n)) return true;
                    used[num] = false;
                    result[index] = result[index + num] = 0; // Backtrack
                }
            }
        }
        return false; // If no valid placement is found
    }
}
