/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool dfs(TreeNode *root, ListNode *head)
    {
        if(!head)
            return true;
        if(!root || root->val != head->val)
            return false;
        return dfs(root->left, head->next) || dfs(root->right, head->next);
    }
    
    bool solve(TreeNode *root, ListNode *head)
    {
        if(!root)
            return false;
        if(dfs(root, head))
            return true;
        return solve(root->left, head) || solve(root->right, head);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        return solve(root, head);
    }
};