/*
 All O`one Data Structure
Hard
Topics
Companies
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.

 

Example 1:

Input
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
Output
[null, null, null, "hello", "hello", null, "hello", "leet"]

Explanation
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"
 

Constraints:

1 <= key.length <= 10
key consists of lowercase English letters.
It is guaranteed that for each call to dec, key is existing in the data structure.
At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.

*/
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Definition for a doubly linked list node
struct Node {
    int count;
    unordered_set<string> keys;
    Node* prev;
    Node* next;
    
    Node(int c) : count(c), prev(nullptr), next(nullptr) {}
};

class AllOne {
private:
    Node* head; // Dummy head (smallest count)
    Node* tail; // Dummy tail (largest count)
    unordered_map<string, Node*> keyCountMap; // Maps key to its node
    unordered_map<int, Node*> countNodeMap; // Maps count to node

public:
    /** Initialize your data structure here. */
    AllOne() {
        head = new Node(0); // Dummy head with count 0
        tail = new Node(0); // Dummy tail with count 0
        head->next = tail;
        tail->prev = head;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (keyCountMap.find(key) == keyCountMap.end()) {
            // Key does not exist, insert with count 1
            if (countNodeMap.find(1) == countNodeMap.end()) {
                // No node with count 1, create it and insert after head
                Node* newNode = new Node(1);
                newNode->keys.insert(key);
                insertNodeAfter(newNode, head);
                countNodeMap[1] = newNode;
            } else {
                // Node with count 1 exists
                countNodeMap[1]->keys.insert(key);
            }
            keyCountMap[key] = countNodeMap[1];
        } else {
            // Key exists, increment its count
            Node* currentNode = keyCountMap[key];
            int newCount = currentNode->count + 1;
            // Remove key from current node
            currentNode->keys.erase(key);
            // Check if next node has count newCount
            if (currentNode->next == tail || currentNode->next->count != newCount) {
                // Create new node
                Node* newNode = new Node(newCount);
                newNode->keys.insert(key);
                insertNodeAfter(newNode, currentNode);
                countNodeMap[newCount] = newNode;
            } else {
                // Next node has the required count
                currentNode->next->keys.insert(key);
            }
            // Update key's node
            keyCountMap[key] = currentNode->next;
            // If current node has no keys, remove it
            if (currentNode->keys.empty()) {
                removeNode(currentNode);
                countNodeMap.erase(currentNode->count);
                delete currentNode;
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (keyCountMap.find(key) == keyCountMap.end()) return; // Key doesn't exist
        
        Node* currentNode = keyCountMap[key];
        int newCount = currentNode->count - 1;
        // Remove key from current node
        currentNode->keys.erase(key);
        
        if (newCount == 0) {
            // Remove key completely
            keyCountMap.erase(key);
        } else {
            // Move key to the previous node with newCount
            if (currentNode->prev == head || currentNode->prev->count != newCount) {
                // Create new node
                Node* newNode = new Node(newCount);
                newNode->keys.insert(key);
                insertNodeAfter(newNode, currentNode->prev);
                countNodeMap[newCount] = newNode;
            } else {
                // Previous node has the required count
                currentNode->prev->keys.insert(key);
            }
            // Update key's node
            keyCountMap[key] = currentNode->prev;
        }
        
        // If current node has no keys, remove it
        if (currentNode->keys.empty()) {
            removeNode(currentNode);
            countNodeMap.erase(currentNode->count);
            delete currentNode;
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (tail->prev == head) return "";
        // Return any key from the last node
        return *(tail->prev->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (head->next == tail) return "";
        // Return any key from the first node
        return *(head->next->keys.begin());
    }
    
private:
    // Helper function to insert newNode after prevNode
    void insertNodeAfter(Node* newNode, Node* prevNode) {
        newNode->prev = prevNode;
        newNode->next = prevNode->next;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
    }
    
    // Helper function to remove a node from the DLL
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    // Destructor to free allocated memory
public:
    ~AllOne() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};
