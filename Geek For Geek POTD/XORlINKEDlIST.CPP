/*
XOR Linked List
Difficulty: MediumAccuracy: 58.15%Submissions: 20K+Points: 4
An ordinary Doubly Linked List requires space for two address fields to store the addresses of previous and next nodes. A memory-efficient version of the Doubly Linked List can be created using only one space for the address field with every node. This memory-efficient Doubly Linked List is called XOR Linked List or Memory Efficient as the list uses bit-wise XOR operation to save space for one address.

Given a stream of data of size N for the linked list, your task is to complete the function insert() and getList(). The insert() function pushes (or inserts at the beginning) the given data in the linked list and the getList()  function returns the linked list as a list.

Note:

A utility function XOR() takes two Node pointers to get the bit-wise XOR of the two Node pointers. Use this function to get the XOR of the two pointers.
The driver code prints the returned list twice, once forward and once backwards.
Examples:

Input:
LinkedList: 9<->5<->4<->7<->3<->10

Output:
10 3 7 4 5 9
9 5 4 7 3 10
Input:
LinkedList: 58<->96<->31

Output:
31 96 58
58 96 31
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= number of nodes, data of nodes <= 105


*/
#include <bits/stdc++.h>
using namespace std;

// Structure of linked list node
struct Node {
    int data;
    struct Node* npx; // XOR of next and previous node addresses

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

// Utility function to get XOR of two node pointers
Node* XOR(Node* a, Node* b) {
    return (Node*) ((uintptr_t)(a) ^ (uintptr_t)(b));
}

// Function to insert a node at the front of the XOR linked list
Node* insert(Node* head, int data) {
    // Create a new node
    Node* newNode = new Node(data);
    
    // Set the npx of the new node as XOR of NULL and current head
    newNode->npx = XOR(NULL, head);
    
    // If the list is not empty, update the current head's npx
    if (head != NULL) {
        // The current head's previous pointer is XOR(NULL, next)
        // To update it, we XOR the existing npx with the new node
        Node* next = XOR(NULL, head->npx);
        head->npx = XOR(newNode, next);
    }
    
    // The new node becomes the new head
    return newNode;
}

// Function to traverse the XOR linked list and return the elements as a vector
vector<int> getList(Node* head) {
    vector<int> result;
    Node* current = head;
    Node* prev = NULL;
    Node* next;

    while (current != NULL) {
        // Add the current node's data to the result
        result.push_back(current->data);
        
        // Calculate the next node using XOR of previous and current node's npx
        next = XOR(prev, current->npx);
        
        // Move to the next node
        prev = current;
        current = next;
    }

    return result;
}

int main() {
    Node* head = NULL;

    // Example 1: Insert elements 10, 3, 7, 4, 5, 9 at the front
    head = insert(head, 10);
    head = insert(head, 3);
    head = insert(head, 7);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 9);

    // Get the list in forward order
    vector<int> forwardList = getList(head);
    
    // Print the list in forward order
    for (int val : forwardList) {
        cout << val << " ";
    }
    cout << endl;
    
    // To get the list in reverse order, simply reverse the forwardList vector
    vector<int> reverseList = forwardList;
    reverse(reverseList.begin(), reverseList.end());
    
    // Print the list in reverse order
    for (int val : reverseList) {
        cout << val << " ";
    }
    cout << endl;

    // Example 2: Insert elements 31, 96, 58 at the front
    Node* head2 = NULL;
    head2 = insert(head2, 31);
    head2 = insert(head2, 96);
    head2 = insert(head2, 58);
    
    // Get the list in forward order
    vector<int> forwardList2 = getList(head2);
    
    // Print the list in forward order
    for (int val : forwardList2) {
        cout << val << " ";
    }
    cout << endl;
    
    // Print the list in reverse order
    reverse(forwardList2.begin(), forwardList2.end());
    for (int val : forwardList2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
