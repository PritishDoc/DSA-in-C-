/*

Linked List Group Reverse
Difficulty: HardAccuracy: 57.08%Submissions: 223K+Points: 8
Given the head a linked list, the task is to reverse every k node in the linked list. If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.

Examples:

Input: head = 1 -> 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8, k = 4
Output: 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5

Explanation: The first 4 elements 1, 2, 2, 4 are reversed first and then the next 4 elements 5, 6, 7, 8. Hence, the resultant linked list is 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5.
Input: head = 1 -> 2 -> 3 -> 4 -> 5, k = 3
Output: 3 -> 2 -> 1 -> 5 -> 4

Explanation: The first 3 elements 1, 2, 3 are reversed first and then left out elements 4, 5 are reversed. Hence, the resultant linked list is 3 -> 2 -> 1 -> 5 -> 4.
Constraints:
1 <= size of linked list <= 105
1 <= data of nodes <= 106
1 <= k <= size of linked list 


*/
class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k == 1) return head; // Base cases

        Node* dummy = new Node(0); // Dummy node to simplify operations
        dummy->next = head;
        Node* prevGroupEnd = dummy;
        Node* current = head;

        while (current) {
            // Check if there are at least k nodes left
            Node* groupEnd = current;
            for (int i = 1; i < k && groupEnd; ++i) {
                groupEnd = groupEnd->next;
            }

            if (!groupEnd) break; // If less than k nodes are left, stop

            Node* nextGroupStart = groupEnd->next; // Save the next group start
            groupEnd->next = nullptr; // Temporarily disconnect the group

            // Reverse the current group
            Node* prev = nullptr;
            Node* curr = current;
            while (curr) {
                Node* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect the reversed group back to the list
            prevGroupEnd->next = groupEnd;
            current->next = nextGroupStart;

            // Move to the next group
            prevGroupEnd = current;
            current = nextGroupStart;
        }

        return dummy->next; // Return the new head
    }
};
