/*
Find length of Loop
Difficulty: EasyAccuracy: 44.26%Submissions: 182K+Points: 2
Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.



Note: 'c' is the position of the node which is the next pointer of the last node of the linkedlist. If c is 0, then there is no loop.

Examples:

Input: LinkedList: 25->14->19->33->10->21->39->90->58->45, c = 4
Output: 7
Explanation: The loop is from 33 to 45. So length of loop is 33->10->21->39-> 90->58->45 = 7. 
The number 33 is connected to the last node of the linkedlist to form the loop because according to the input the 4th node from the beginning(1 based indexing) 
will be connected to the last node for the loop.
 
Input: LinkedList: 5->4, c = 0
Output: 0
Explanation: There is no loop.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= no. of nodes <= 106
0 <= node.data <=106Find length of Loop
Difficulty: EasyAccuracy: 44.26%Submissions: 182K+Points: 2
Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.



Note: 'c' is the position of the node which is the next pointer of the last node of the linkedlist. If c is 0, then there is no loop.

Examples:

Input: LinkedList: 25->14->19->33->10->21->39->90->58->45, c = 4
Output: 7
Explanation: The loop is from 33 to 45. So length of loop is 33->10->21->39-> 90->58->45 = 7. 
The number 33 is connected to the last node of the linkedlist to form the loop because according to the input the 4th node from the beginning(1 based indexing) 
will be connected to the last node for the loop.
 
Input: LinkedList: 5->4, c = 0
Output: 0
Explanation: There is no loop.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= no. of nodes <= 106
0 <= node.data <=106
*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node *slow = head;
        Node *fast = head;
        
        // Step 1: Detect loop using Floyd's Cycle Detection Algorithm
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            // Loop detected
            if (slow == fast) {
                // Step 2: Count the number of nodes in the loop
                return countLoopLength(slow);
            }
        }
        
        // No loop
        return 0;
    }
    
    // Helper function to count the number of nodes in the loop
    int countLoopLength(Node *loopNode) {
        Node *temp = loopNode;
        int length = 1;
        
        while (temp->next != loopNode) {
            length++;
            temp = temp->next;
        }
        
        return length;
    }
};
