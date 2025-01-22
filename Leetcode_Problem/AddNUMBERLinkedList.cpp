/*
Add Number Linked Lists
Difficulty: MediumAccuracy: 34.52%Submissions: 310K+Points: 4
Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task is to return the head of the linked list representing the sum of these two numbers.

For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Examples:

Input: num1 = 4 - > 5, num2 = 3 -> 4 -> 5
Output:  3 -> 9 -> 0
 
Explanation: Given numbers are 45 and 345. There sum is 390.
Input: num1 = 0 -> 0 -> 6 -> 3, num2 = 0 -> 7 
Output: 7 -> 0 
 
Explanation: Given numbers are 63 and 7. There sum is 70.
Constraints:
1 <= size of both linked lists <= 106
0 <= elements of both linked lists <= 9




*/
Wrong Answer. !!!
Ask Yogi Bot
Possibly your code does not work correctly for multiple test-cases (TCs).

The first test case where your code failed:

Test Cases Passed: 
211 /1111
For Input: 
0 3 4 3 4 7 9 1 7 3 0 5 5 0 5 1 4 9 3 7 4 0 5 0 5 3 3 8 7 0 1 7 7 2 1 6 9 5 0 2 9 8 0 6 7 6 7 2 7 2 4 2 1 6 8 9 1 4 6 9 0 2 0 3 3 5 8 0 5 8 6 9 9 8 3 2 2 5 2 0 4 0 6 8 1 5 3 4 6 9 1 2 1 5 6 3 7 9 2 8 ...
 Input is too large Download Full File 
Your Code's output is: 
0 6 5 5 6 4 7 1 6 5 5 7 9 8 5 0 7 9 8 3 3 3 6 0 7 1 5 0 6 5 6 3 5 6 0 8 1 1 7 0 2 5 6 7 6 7 6 2 1 2 7 7 9 7 7 4 7 8 1 5 9 5 0 7 9 8 8 5 8 9 3 3 2 6 5 9 0 3 0 9 7 7 8 3 4 7 2 7 1 8 5 6 1 4 9 1 6 3 8 2 ...
 Your Output is too large Download Full File 
It's Correct output is: 
6 5 5 6 4 7 1 6 5 5 7 9 8 5 0 7 9 8 3 3 3 6 0 7 1 5 0 6 5 6 3 5 6 0 8 1 1 7 0 2 5 6 7 6 7 6 2 1 2 7 7 9 7 7 4 7 8 1 5 9 5 0 7 9 8 8 5 8 9 3 3 2 6 5 9 0 3 0 9 7 7 8 3 4 7 2 7 1 8 5 6 1 4 9 1 6 3 8 2 2 ...
 Correct Output is too large Download Full File 
Kick start your career with GfG 160!
arrow
Geek Tip:
Solving the sample test case does not guarantee correctness of solution as your code is checked against multiple test cases.
Avoid using static/global variables in your code.
Do not print anything unless mentioned in the problem statement. Avoid unnecessary new line characters.