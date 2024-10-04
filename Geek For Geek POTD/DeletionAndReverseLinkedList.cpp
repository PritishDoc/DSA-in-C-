/*


Deletion and Reverse in Circular Linked List
Difficulty: MediumAccuracy: 60.7%Submissions: 38K+Points: 4
Given a Circular Linked List. The task is to delete the given node, key in the circular linked list, and reverse the circular linked list.

Note:

You don't have to print anything, just return the head of the modified list in each function.
Nodes may consist of Duplicate values.
The key may or may not be present.
Examples:

Input: Linked List: 2->5->7->8->10, key = 8

Output: 10->7->5->2 
Explanation: After deleting 8 from the given circular linked list, it has elements as 2, 5, 7, 10. Now, reversing this list will result in 10, 7, 5, 2 & the resultant list is also circular.
Input: Linked List: 1->7->8->10, key = 8

Output: 10->7->1
Explanation: After deleting 8 from the given circular linked list, it has elements as 1, 7,10. Now, reversing this list will result in 10, 7, 1 & the resultant list is also circular.
Input: Linked List: 3->6->4->10, key = 9
Output: 10->4->6->3
Explanation: As there no key present in the list, so simply reverse the list & the resultant list is also circular.
Expected Time Complexity: O(n)
Expected Auxillary Space: O(1)

Constraints:
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
  public:
    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        if (head == NULL)
            return head;

        // If the list contains only one node
        if (head->data == key && head->next == head) {
            delete head;
            return NULL;
        }

        Node* current = head;
        Node* prev = NULL;

        // To handle deletion of head node
        if (current->data == key) {
            // Find the last node
            while (current->next != head)
                current = current->next;
            // Current now points to the last node
            current->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Traverse the list to find the node to delete
        prev = head;
        current = head->next;
        while (current != head) {
            if (current->data == key) {
                prev->next = current->next;
                delete current;
                return head;
            }
            prev = current;
            current = current->next;
        }

        // If key not found, return the original head
        return head;
    }

    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        if (head == NULL || head->next == head)
            return head;

        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        Node* originalHead = head;

        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != originalHead);

        // After reversing, head becomes the last node
        // So connect the original head's next to the new head (prev)
        originalHead->next = prev;
        head = prev;

        return head;
    }
};

// Below is some helper code to test the implementation.
// You can use this to verify the correctness of the above functions.

int main() {
    // Example 1:
    // Input: 2->5->7->8->10, key = 8
    // Expected Output after deletion and reversal: 10->7->5->2

    // Creating the circular linked list: 2->5->7->8->10->2
    Node* head1 = new Node(2);
    head1->next = new Node(5);
    head1->next->next = new Node(7);
    head1->next->next->next = new Node(8);
    head1->next->next->next->next = new Node(10);
    head1->next->next->next->next->next = head1; // Making it circular

    Solution sol;
    // Delete node with key 8
    head1 = sol.deleteNode(head1, 8);
    // Reverse the list
    head1 = sol.reverse(head1);

    // Printing the reversed list
    Node* temp = head1;
    if (head1 != NULL) {
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != head1)
                cout << "->";
        } while (temp != head1);
        cout << endl;
    }

    // You can add more test cases similarly.

    // Free allocated memory
    if (head1 != NULL) {
        Node* current = head1->next;
        head1->next = NULL; // Break the circular reference to prevent infinite loop
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head1;
    }

    return 0;
}
