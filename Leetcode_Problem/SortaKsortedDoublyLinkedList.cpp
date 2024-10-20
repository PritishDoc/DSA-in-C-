/*

Sort a k sorted doubly linked list
Difficulty: EasyAccuracy: 55.57%Submissions: 16K+Points: 2
Given a doubly linked list, each node is at most k-indices away from its target position. The problem is to sort the given doubly linked list. The distance can be assumed in either of the directions (left and right).

Examples :

Input: Doubly Linked List : 3 <-> 2 <-> 1 <-> 5 <-> 6 <-> 4 , k = 2
Output: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6

Explanation: After sorting the given 2-sorted list is 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6.
Input: Doubly Linked List : 5 <-> 6 <-> 7 <-> 3 <-> 4 <-> 4 , k = 3
Output: 3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7

Explanation: After sorting the given 3-sorted list is 3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7.
Expected Time Complexity: O(n*logk)
Expected Auxiliary Space: O(k)
Constraints:
1 <= number of nodes <= 105
1 <= k < number of nodes
1 <= node->data <= 109

*/
#include <bits/stdc++.h>
using namespace std;

class DLLNode {
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
public:
    // Function to sort a k-sorted doubly linked list
    DLLNode* sortAKSortedDLL(DLLNode* head, int k) {
        if (!head) return nullptr;

        // Create a priority queue (min-heap) to hold nodes and compare based on their values
        priority_queue<DLLNode*, vector<DLLNode*>, function<bool(DLLNode*, DLLNode*)>> minHeap(
            [](DLLNode* a, DLLNode* b) { return a->data > b->data; });

        DLLNode* newHead = nullptr; // New head after sorting
        DLLNode* lastSorted = nullptr; // Pointer to track the last sorted node

        // Step 1: Insert the first k+1 nodes into the min-heap
        DLLNode* curr = head;
        for (int i = 0; curr != nullptr && i <= k; i++) {
            minHeap.push(curr);
            curr = curr->next;
        }

        // Step 2: Process the remaining nodes by extracting the min element from the heap
        while (!minHeap.empty()) {
            // Extract the smallest node from the heap
            DLLNode* smallest = minHeap.top();
            minHeap.pop();

            // If it's the first node, set it as the new head
            if (!newHead) {
                newHead = smallest;
                lastSorted = newHead;
                lastSorted->prev = nullptr;
            } else {
                // Attach to the sorted portion
                lastSorted->next = smallest;
                smallest->prev = lastSorted;
                lastSorted = smallest;
            }

            // Move to the next node in the unsorted list and push it into the heap
            if (curr) {
                minHeap.push(curr);
                curr = curr->next;
            }
        }

        // Terminate the sorted list
        lastSorted->next = nullptr;
        return newHead;
    }
};

// Helper function to print the doubly linked list
void printList(DLLNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main driver code
int main() {
    // Creating a k-sorted doubly linked list
    DLLNode* head = new DLLNode(3);
    head->next = new DLLNode(2);
    head->next->prev = head;
    head->next->next = new DLLNode(1);
    head->next->next->prev = head->next;
    head->next->next->next = new DLLNode(5);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new DLLNode(6);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new DLLNode(4);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    int k = 2; // k value

    Solution solution;
    DLLNode* sortedHead = solution.sortAKSortedDLL(head, k);

    // Print the sorted doubly linked list
    printList(sortedHead);

    return 0;
}
