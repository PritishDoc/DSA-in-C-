/*
Delete Alternate Nodes
Difficulty: EasyAccuracy: 56.09%Submissions: 79K+Points: 2
Given a Singly Linked List, Delete all alternate nodes of the list ie delete all the nodes present in even positions.

Examples :

Input: LinkedList: 1->2->3->4->5->6
 
Output: 1->3->5

Explanation: Deleting alternate nodes ie 2, 4, 6 results in the linked list with elements 1->3->5.
Input: LinkedList: 99->59->42->20
 
Output: 99->42
 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 103


*/
#include <iostream>
using namespace std;

// Structure of a Node in a singly linked list
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    void deleteAlt(struct Node *head) {
        // Check if the list is empty
        if (head == NULL)
            return;

        // Pointer to track the current node
        Node* current = head;

        // Traverse the list and delete alternate nodes
        while (current != NULL && current->next != NULL) {
            // Skip the next node by adjusting the next pointer
            Node* temp = current->next;  // Store the node to be deleted
            current->next = current->next->next;  // Skip the alternate node
            delete temp;  // Free memory of the skipped node

            // Move to the next node
            current = current->next;
        }
    }
};

// Helper function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code to test the solution
int main() {
    // Creating a linked list 1->2->3->4->5->6
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    Solution ob;
    cout << "Original List: ";
    printList(head);

    // Deleting alternate nodes
    ob.deleteAlt(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}
