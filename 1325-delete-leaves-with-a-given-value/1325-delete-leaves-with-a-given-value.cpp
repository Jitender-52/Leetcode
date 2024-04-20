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
    
    int value;
    
    bool solve(TreeNode *root)
    {
        if(!root)
            return true;
        bool l = solve(root->left);
        bool r = solve(root->right);
        if(l)
            root->left = NULL;
        if(r)
            root->right = NULL;
        if(l && r && root->val == value)
            return true;
        return false;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        value = target;
        solve(root);
        if(!root->left && !root->right && root->val == value)
            root = NULL;
        return root;
    }
};