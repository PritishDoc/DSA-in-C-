/*

Split Linked List Alternatingly
Difficulty: EasyAccuracy: 42.46%Submissions: 27K+Points: 2
Given a singly linked list's head. Your task is to complete the function alternatingSplitList() that splits the given linked list into two smaller lists. The sublists should be made from alternating elements from the original list.
Note: 

The sublist should be in the order with respect to the original list.
Your have to return an array containing the both sub-linked lists.
Examples:

Input: LinkedList = 0->1->0->1->0->1
Output: 0->0->0 , 1->1->1
Explanation: After forming two sublists of the given list as required, we have two lists as: 0->0->0 and 1->1->1.

Input: LinkedList = 2->5->8->9->6
Output: 2->8->6 , 5->9
Explanation: After forming two sublists of the given list as required, we have two lists as: 2->8->6 and 5->9.
Input: LinkedList: 7 
Output: 7 , <empty linked list>
Constraints:
1 <= number of nodes <= 100
1 <= node -> data <= 104


*/
class Solution {
  public:
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Create dummy nodes for the two lists
        Node* dummy1 = new Node(0);  // First list
        Node* dummy2 = new Node(0);  // Second list
        
        Node* list1 = dummy1;  // Pointer for first list
        Node* list2 = dummy2;  // Pointer for second list
        Node* current = head;  // Pointer to traverse the original list
        
        // Flag to toggle between two lists
        bool toggle = true;
        
        // Traverse the original linked list
        while (current != nullptr) {
            if (toggle) {
                list1->next = current;  // Add to first list
                list1 = list1->next;    // Move the pointer of the first list
            } else {
                list2->next = current;  // Add to second list
                list2 = list2->next;    // Move the pointer of the second list
            }
            toggle = !toggle;  // Alternate the lists
            current = current->next;  // Move to the next node in the original list
        }
        
        // Terminate the lists
        list1->next = nullptr;
        list2->next = nullptr;
        
        // Return the heads of the two sublists (skipping dummy nodes)
        return {dummy1->next, dummy2->next};
    }
};
