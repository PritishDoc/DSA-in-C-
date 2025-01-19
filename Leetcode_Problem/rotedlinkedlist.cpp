/*

Rotate a Linked List
Difficulty: MediumAccuracy: 39.95%Submissions: 269K+Points: 4
Given the head of a singly linked list, your task is to left rotate the linked list k times.

Examples:

Input: head = 10 -> 20 -> 30 -> 40 -> 50, k = 4
Output: 50 -> 10 -> 20 -> 30 -> 40
Explanation:
Rotate 1: 20 -> 30 -> 40 -> 50 -> 10
Rotate 2: 30 -> 40 -> 50 -> 10 -> 20
Rotate 3: 40 -> 50 -> 10 -> 20 -> 30
Rotate 4: 50 -> 10 -> 20 -> 30 -> 40

Input: head = 10 -> 20 -> 30 -> 40 , k = 6
Output: 30 -> 40 -> 10 -> 20 
 
Constraints:

1 <= number of nodes <= 105
0 <= k <= 109
0 <= data of node <= 10

*/
class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (!head || k == 0) return head; // Edge cases: empty list or no rotations
        
        // Find the length of the list
        Node* current = head;
        int length = 1;
        while (current->next) {
            current = current->next;
            length++;
        }
        
        // Connect the last node to the head to make it circular
        current->next = head;
        
        // Calculate the effective rotations
        k = k % length;
        if (k == 0) { // If no rotation is needed
            current->next = NULL; // Break the circular link
            return head;
        }
        
        // Traverse to the node just before the new head
        for (int i = 0; i < k; i++) {
            current = current->next;
        }
        
        // Break the loop and set the new head
        head = current->next;
        current->next = NULL;
        
        return head;
    }
};
