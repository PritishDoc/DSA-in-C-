/*

Parenthesis Checker
Difficulty: EasyAccuracy: 28.56%Submissions: 592K+Points: 2
Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

Note: The driver code prints "balanced" if function return true, otherwise it prints "not balanced".

Examples :

Input: {([])}
Output: true
Explanation: { ( [ ] ) }. Same colored brackets can form balanced pairs, with 0 number of unbalanced bracket.
Input: ()
Output: true
Explanation: (). Same bracket can form balanced pairs,and here only 1 type of bracket is present and in balanced way.
Input: ([]
Output: false
Explanation: ([]. Here square bracket is balanced but the small bracket is not balanced and Hence , the output will be unbalanced.
Expected Time Complexity: O(|x|)
Expected Auixilliary Space: O(|x|)

Constraints:
1 ≤ |x| ≤ 105

 
*/
class Solution {
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x) {
        std::stack<char> s;

        // Traverse the string
        for (char c : x) {
            // If it's an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
            } 
            // If it's a closing bracket, check for a matching opening bracket
            else {
                // If stack is empty, it's unbalanced
                if (s.empty()) return false;

                char top = s.top();
                s.pop();

                // Check if the current closing bracket matches the top opening bracket
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If stack is not empty, there are unmatched opening brackets
        return s.empty();
    }
};