vector<int> leftView(Node *root) {
    vector<int> result;
    if (!root) return result;  // If tree is empty, return an empty list
    
    queue<Node*> q;  // Create a queue for level order traversal
    q.push(root);
    
    while (!q.empty()) {
        int n = q.size();  // Number of nodes at the current level
        
        // Traverse all nodes of the current level
        for (int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();
            
            // If this is the first node of the current level, add it to the result
            if (i == 0) {
                result.push_back(curr->data);
            }
            
            // Enqueue the left and right children of the current node
            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }
        }
    }
    
    return result;  // Return the left view of the binary tree
}