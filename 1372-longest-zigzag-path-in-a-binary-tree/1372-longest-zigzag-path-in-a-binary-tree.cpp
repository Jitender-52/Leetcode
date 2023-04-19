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
    
    void path(TreeNode *root, int count, int &ans, bool left)
    {
        if(!root)
            return;
        ans = max(ans, count);
        
        if(left)
        {
            path(root->right, count+1, ans, !left);
            path(root->left, 1, ans, left);
        }
        else
        {
            path(root->left, count+1, ans, !left);
            path(root->right, 1, ans, left);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        path(root, 0, ans, true);
        path(root, 0, ans, false);
        return ans;
    }
};