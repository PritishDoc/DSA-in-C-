/*
Difficulty: HardAccuracy: 53.53%Submissions: 76K+Points: 8
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.


Examples : 

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5

Expected Time Complexity: O(number of nodes)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ number of nodes ≤ 105

1 ≤ values of nodes ≤ 105
*/
class Solution {
public:
    int minTime(Node* root, int target) {
        if (!root) return 0;
        
        // Step 1: Create a parent map and find the target node
        std::unordered_map<Node*, Node*> parentMap; // Node -> Parent mapping
        Node* targetNode = NULL;
        createParentMap(root, parentMap, targetNode, target);
        
        // Step 2: Perform BFS to burn the tree
        return burnTree(targetNode, parentMap);
    }

private:
    // Function to create a parent map and find the target node
    void createParentMap(Node* root, std::unordered_map<Node*, Node*>& parentMap, Node*& targetNode, int target) {
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            // Check if this is the target node
            if (current->data == target) {
                targetNode = current;
            }

            // Push left and right children to the queue and set their parent
            if (current->left) {
                parentMap[current->left] = current;
                q.push(current->left);
            }

            if (current->right) {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }
    }

    // Function to perform BFS and calculate the minimum time to burn the tree
    int burnTree(Node* targetNode, std::unordered_map<Node*, Node*>& parentMap) {
        std::queue<Node*> q;
        std::set<Node*> visited; // Set to track visited nodes
        q.push(targetNode);
        visited.insert(targetNode);

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool anyBurned = false;

            // Process all nodes at the current level
            for (int i = 0; i < size; ++i) {
                Node* current = q.front();
                q.pop();

                // Burn the left child
                if (current->left && visited.find(current->left) == visited.end()) {
                    anyBurned = true;
                    q.push(current->left);
                    visited.insert(current->left);
                }

                // Burn the right child
                if (current->right && visited.find(current->right) == visited.end()) {
                    anyBurned = true;
                    q.push(current->right);
                    visited.insert(current->right);
                }

                // Burn the parent
                if (parentMap.find(current) != parentMap.end() && visited.find(parentMap[current]) == visited.end()) {
                    anyBurned = true;
                    q.push(parentMap[current]);
                    visited.insert(parentMap[current]);
                }
            }

            // Increment time if any nodes were burned at this level
            if (anyBurned) {
                time++;
            }
        }

        return time;
    }
};
