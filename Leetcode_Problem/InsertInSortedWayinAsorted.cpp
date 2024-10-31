/*
Insert in Sorted way in a Sorted DLL
Difficulty: MediumAccuracy: 28.25%Submissions: 51K+Points: 4
Given a sorted doubly linked list and an element x, you need to insert the element x into the correct position in the sorted Doubly linked list(DLL).

Note: The DLL is sorted in ascending order

Example:

Input: LinkedList: 3->5->8->10->12 , x = 9

Output: 3->5->8->9->10->12

Explanation: Here node 9 is inserted in the Doubly Linked-List.
Input: LinkedList: 1->4->10->11 , x = 15

Output: 1->4->10->11->15

Constraints:
1 <= number of nodes <= 103
1 <= node -> data , x <= 104

*/
#include <iostream>
using namespace std;

// Definition for a doubly linked list node.
struct Node {
    int data;
    Node* next;
    Node* prev;
};

class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Create a new node and manually initialize its fields
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        // Case 1: If the list is empty
        if (head == nullptr) {
            return newNode;
        }

        // Case 2: Insert at the beginning if x is smaller than head's data
        if (x <= head->data) {
            newNode->next = head;
            head->prev = newNode;
            return newNode;  // New node becomes the new head of the list
        }

        // Case 3: Traverse to find the correct position to insert
        Node* current = head;
        while (current->next != nullptr && current->next->data < x) {
            current = current->next;
        }

        // Case 4: Insert at the end if x is greater than all current nodes' data
        if (current->next == nullptr) {
            current->next = newNode;
            newNode->prev = current;
        } else {
            // Insert between current and current->next
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }

        return head;
    }
};

// Helper function to print the doubly linked list
void printDoublyLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function to test the sortedInsert function
int main() {
    Solution obj;

    // Creating a sorted doubly linked list: 1 -> 9 -> 16 -> 25 -> 78
    Node* head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 9;
    head->next->prev = head;
    head->next->next = new Node();
    head->next->next->data = 16;
    head->next->next->prev = head->next;
    head->next->next->next = new Node();
    head->next->next->next->data = 25;
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 78;
    head->next->next->next->next->prev = head->next->next->next;

    int valueToInsert = 2;

    // Insert the new value and get the new head
    head = obj.sortedInsert(head, valueToInsert);

    // Print the updated list
    printDoublyLinkedList(head);

    return 0;
}
