/*
Middle of a Linked List
Difficulty: EasyAccuracy: 57.93%Submissions: 343K+Points: 2
Given the head of a linked list, the task is to find the middle. For example, the middle of 1-> 2->3->4->5 is 3. If there are two middle nodes (even count), return the second middle. For example, middle of 1->2->3->4->5->6 is 4.

Examples:

Input: Linked list: 1->2->3->4->5
Output: 3

Explanation: The given linked list is 1->2->3->4->5 and its middle is 3.
Input: Linked list: 2->4->6->7->5->1
Output: 7 

Explanation: The given linked list is 2->4->6->7->5->1 and its middle is 7.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= no. of nodes <= 105
*/
class Solution {
public:
    // Function to return the data of the middle node of the linked list
    int getMiddle(Node* head) {
        // Step 1: If the list is empty, return -1
        if (head == NULL) return -1;

        // Step 2: Initialize slow and fast pointers
        Node* slow = head;
        Node* fast = head;

        // Step 3: Traverse the list with slow and fast pointers
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next; // Move slow by 1 step
            fast = fast->next->next; // Move fast by 2 steps
        }

        // Step 4: When the loop ends, slow will be at the middle
        return slow->data;
    }
};
