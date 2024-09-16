/*
Longest valid Parentheses
Difficulty: HardAccuracy: 26.13%Submissions: 118K+Points: 8
Given a string str consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
Opening parenthesis must be closed in the correct order.
Examples :

Input: str = ((()
Output: 2
Explaination: The longest valid parenthesis substring is "()".
Input: str = )()())
Output: 4
Explaination: The longest valid parenthesis substring is "()()".
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |str| ≤ 105
*/
class Solution {
  public:
    int maxLength(string& str) {
        // Stack to store indices of parentheses
        stack<int> st;
        // Initialize the stack with -1 to handle edge cases
        st.push(-1);
        
        int max_len = 0; // To store the length of the longest valid substring
        
        // Traverse the string
        for (int i = 0; i < str.length(); i++) {
            // If we encounter an opening parenthesis, push its index onto the stack
            if (str[i] == '(') {
                st.push(i);
            } else {
                // If we encounter a closing parenthesis, pop from the stack
                st.pop();
                
                // If the stack is empty, push the current index onto the stack
                if (st.empty()) {
                    st.push(i);
                } else {
                    // The current length of the valid substring is the difference between
                    // the current index and the index at the top of the stack
                    max_len = max(max_len, i - st.top());
                }
            }
        }
        
        return max_len;
    }
};