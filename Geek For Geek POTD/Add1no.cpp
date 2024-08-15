/*
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;  // Store the next node
            curr->next = prev;  // Reverse the current node's pointer
            prev = curr;        // Move the prev and curr pointers one step forward
            curr = next;
        }

        return prev;  // prev becomes the new head after reversal
    }

    Node* addOne(Node* head) {
        // Step 1: Reverse the linked list
        head = reverse(head);

        // Step 2: Add one to the reversed list
        Node* curr = head;
        int carry = 1;

        while (curr != NULL) {
            int sum = curr->data + carry;
            carry = sum / 10;   // Calculate the carry
            curr->data = sum % 10;  // Update the current node with the new digit

            if (carry == 0) break;  // No more carry to propagate, break early

            if (curr->next == NULL && carry) {
                curr->next = new Node(carry);  // If at the last node and still have carry, add a new node
                carry = 0; // Carry is handled
            }

            curr = curr->next; // Move to the next node
        }

        // Step 3: Reverse the list back to its original order
        head = reverse(head);

        return head;
    }
};

// Helper function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data;
        if (node->next != NULL) cout << "->";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Create a linked list 4->5->6
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(6);

    // Add one to the linked list
    head = solution.addOne(head);

    // Print the result
    printList(head);  // Expected output: 457

    return 0;
}


*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;  // Store the next node
            curr->next = prev;  // Reverse the current node's pointer
            prev = curr;        // Move the prev and curr pointers one step forward
            curr = next;
        }

        return prev;  // prev becomes the new head after reversal
    }

    Node* addOne(Node* head) {
        // Step 1: Reverse the linked list
        head = reverse(head);

        // Step 2: Add one to the reversed list
        Node* curr = head;
        int carry = 1;

        while (curr != NULL) {
            int sum = curr->data + carry;
            carry = sum / 10;   // Calculate the carry
            curr->data = sum % 10;  // Update the current node with the new digit

            if (carry == 0) break;  // No more carry to propagate, break early

            if (curr->next == NULL && carry) {
                curr->next = new Node(carry);  // If at the last node and still have carry, add a new node
                carry = 0; // Carry is handled
            }

            curr = curr->next; // Move to the next node
        }

        // Step 3: Reverse the list back to its original order
        head = reverse(head);

        return head;
    }
};

// Helper function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data;
        if (node->next != NULL) cout << "->";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Create a linked list 4->5->6
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(6);

    // Add one to the linked list
    head = solution.addOne(head);

    // Print the result
    printList(head);  // Expected output: 457

    return 0;
}
