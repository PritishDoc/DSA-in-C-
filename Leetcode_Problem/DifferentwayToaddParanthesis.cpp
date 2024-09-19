/*
Different Ways to Add Parentheses

Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
 

Constraints:

1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].
The integer values in the input expression do not have a leading '-' or '+' denoting the sign.
*/
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Memoization cache to store previously computed results
    unordered_map<string, vector<int>> memo;
    
    vector<int> diffWaysToCompute(string expression) {
        // If the expression result is already computed, return it
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }
        
        vector<int> result;
        
        // Loop through each character in the expression
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            
            // If the character is an operator
            if (c == '+' || c == '-' || c == '*') {
                // Split the expression into left and right parts
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);
                
                // Recursively calculate all possible results for left and right parts
                vector<int> leftResults = diffWaysToCompute(left);
                vector<int> rightResults = diffWaysToCompute(right);
                
                // Combine the results from the left and right parts based on the operator
                for (int leftVal : leftResults) {
                    for (int rightVal : rightResults) {
                        if (c == '+') {
                            result.push_back(leftVal + rightVal);
                        } else if (c == '-') {
                            result.push_back(leftVal - rightVal);
                        } else if (c == '*') {
                            result.push_back(leftVal * rightVal);
                        }
                    }
                }
            }
        }
        
        // If no operator was found, the expression is a single number
        if (result.empty()) {
            result.push_back(stoi(expression));
        }
        
        // Store the result in the memoization cache
        memo[expression] = result;
        return result;
    }
};
