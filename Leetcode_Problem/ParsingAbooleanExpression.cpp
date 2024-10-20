/*
 Parsing A Boolean Expression
Hard
Topics
Companies
Hint
A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.

 

Example 1:

Input: expression = "&(|(f))"
Output: false
Explanation: 
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.
Example 2:

Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.
Example 3:

Input: expression = "!(&(f,t))"
Output: true
Explanation: 
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.
 

Constraints:

1 <= expression.length <= 2 * 104
expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.
*/
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;  // Stack to hold characters as we process the expression

        // Traverse the entire expression
        for (char ch : expression) {
            // If the character is not a closing parenthesis, we push it onto the stack
            if (ch != ')') {
                if (ch != ',') {
                    stk.push(ch);  // We ignore commas as they are separators
                }
            } else {
                // When we encounter a closing parenthesis ')', we evaluate the expression inside the parentheses
                vector<char> values;
                
                // Pop elements until we find the opening parenthesis '('
                while (stk.top() != '(') {
                    values.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();  // Remove the '(' from the stack

                // The operator before the '(' determines how we evaluate the expression
                char op = stk.top();
                stk.pop();  // Pop the operator ('!', '&', '|')
                
                // Evaluate based on the operator
                if (op == '!') {
                    // Logical NOT: there's only one value inside the parentheses
                    stk.push(values[0] == 'f' ? 't' : 'f');
                } else if (op == '&') {
                    // Logical AND: all values must be true for the result to be true
                    bool result = true;
                    for (char val : values) {
                        if (val == 'f') {
                            result = false;
                            break;
                        }
                    }
                    stk.push(result ? 't' : 'f');
                } else if (op == '|') {
                    // Logical OR: at least one value must be true for the result to be true
                    bool result = false;
                    for (char val : values) {
                        if (val == 't') {
                            result = true;
                            break;
                        }
                    }
                    stk.push(result ? 't' : 'f');
                }
            }
        }

        // The final result will be the only element left in the stack
        return stk.top() == 't';
    }
};
