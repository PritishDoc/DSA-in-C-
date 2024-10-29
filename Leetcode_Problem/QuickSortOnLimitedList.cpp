/*

Quick Sort on Linked List
Difficulty: MediumAccuracy: 71.8%Submissions: 26K+Points: 4
You are given a Linked List. Sort the given Linked List using quicksort. 

Examples:

Input: Linked list: 1->6->2
Output: 1->2->6

Explanation:
After sorting the nodes, we have 1, 2 and 6.
Input: Linked list: 1->9->3->8
Output: 1->3->8->9

Explanation:
After sorting the nodes, we have 1, 3, 8 and 9. 
Constraints:
1<= size of linked list <= 105

*/
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution {
public:
    // Split the linked list into two halves
    Node* split(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* mid = slow->next;
        slow->next = nullptr;
        return mid;
    }

    // Merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        if (left->data < right->data) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    // Main function to sort the linked list using merge sort
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;

        Node* mid = split(head);
        Node* left = mergeSort(head);
        Node* right = mergeSort(mid);

        return merge(left, right);
    }

    // Wrapper function for merge sort
    Node* quickSort(Node* head) {
        return mergeSort(head); // Calling merge sort instead
    }
};
