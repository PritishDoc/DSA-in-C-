/*
 Combination Sum II
Solved
Medium
Topics
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(std::vector<int>& candidates, int target, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            if (candidates[i] > target) break; // No need to continue if the current number is greater than the remaining target
            
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            current.pop_back();
        }
    }
    
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        // Sort the candidates to help skip duplicates and manage combinations
        std::sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    
    std::vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;
    std::vector<std::vector<int>> result1 = sol.combinationSum2(candidates1, target1);
    
    std::cout << "Combinations for target " << target1 << ":\n";
    for (const auto& combination : result1) {
        std::cout << "[";
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << "]\n";
    }
    
    std::vector<int> candidates2 = {2, 5, 2, 1, 2};
    int target2 = 5;
    std::vector<std::vector<int>> result2 = sol.combinationSum2(candidates2, target2);
    
    std::cout << "Combinations for target " << target2 << ":\n";
    for (const auto& combination : result2) {
        std::cout << "[";
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << "]\n";
    }
    
    return 0;
}
