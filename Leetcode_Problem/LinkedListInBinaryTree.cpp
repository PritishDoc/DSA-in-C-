/*
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    
private:
    bool dfs(TreeNode* root, ListNode* head) {
        if (!head) return true;
        if (!root) return false;
        if (root->val != head->val) return false;
        return dfs(root->left, head->next) || dfs(root->right, head->next);
    }
};
*/