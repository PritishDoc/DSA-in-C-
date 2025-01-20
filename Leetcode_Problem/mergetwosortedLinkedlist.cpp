/*

Merge two sorted linked lists
Difficulty: MediumAccuracy: 62.91%Submissions: 172K+Points: 4
Given the head of two sorted linked lists consisting of nodes respectively. The task is to merge both lists and return the head of the sorted merged list.

Examples:

Input: head1 = 5 -> 10 -> 15 -> 40, head2 = 2 -> 3 -> 20
Output: 2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40
Explanation:

Input: head1 = 1 -> 1, head2 = 2 -> 4
Output: 1 -> 1 -> 2 -> 4
Explanation:

Constraints:
1 <= no. of nodes<= 103
0 <= node->data <= 10

*/
class Solution {
public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // Create a dummy node to act as the starting point of the merged list
        Node* dummy = new Node(-1);
        Node* current = dummy;

        // Traverse both lists and pick the smaller node
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->data <= head2->data) {
                current->next = head1;
                head1 = head1->next;
            } else {
                current->next = head2;
                head2 = head2->next;
            }
            current = current->next;
        }

        // Attach the remaining nodes of the non-empty list
        if (head1 != nullptr) {
            current->next = head1;
        } else if (head2 != nullptr) {
            current->next = head2;
        }

        // Return the merged list (skip the dummy node)
        Node* mergedHead = dummy->next;
        delete dummy; // Free the dummy node
        return mergedHead;
    }
};
