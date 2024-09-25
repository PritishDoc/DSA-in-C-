/*

Palindrome Linked List
Difficulty: MediumAccuracy: 41.48%Submissions: 334K+Points: 4
Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.

Examples:

Input: LinkedList: 1->2->1->1->2->1
Output: true
Explanation: The given linked list is 1->2->1->1->2->1 , which is a palindrome and Hence, the output is true.

Input: LinkedList: 1->2->3->4
Output: false
Explanation: The given linked list is 1->2->3->4, which is not a palindrome and Hence, the output is false.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1) 
Note: You should not use the recursive stack space as well

Constraints:
1 <= number of nodes <= 105
1 ≤ node->data ≤ 103

*/
class Solution {
public:
    // Function to reverse a linked list starting from the given head
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;  // Save next node
            curr->next = prev;  // Reverse current node's pointer
            prev = curr;        // Move prev and curr one step forward
            curr = next;
        }

        return prev;  // New head of the reversed list
    }

    // Function to check whether the list is a palindrome
    bool isPalindrome(Node* head) {
        if (head == NULL || head->next == NULL) {
            return true;  // Empty or single node list is a palindrome
        }

        // Step 1: Find the middle of the list
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        Node* secondHalf = reverseList(slow);

        // Step 3: Compare the first and second halves
        Node* firstHalf = head;
        Node* reversedHalf = secondHalf;

        while (reversedHalf != NULL) {
            if (firstHalf->data != reversedHalf->data) {
                return false;  // The list is not a palindrome
            }
            firstHalf = firstHalf->next;
            reversedHalf = reversedHalf->next;
        }

        // Step 4 (Optional): Restore the list (reverse the second half back)
        reverseList(secondHalf);

        return true;  // The list is a palindrome
    }
};