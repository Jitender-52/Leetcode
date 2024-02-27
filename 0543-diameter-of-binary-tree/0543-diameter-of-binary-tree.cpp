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
    
    int ans = 0;
    int solve(TreeNode *root)
    {
        if(!root)
            return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        ans = max(ans, l + r + 1);
        return 1 + max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans - 1; // because answer is the number of node in the longest path so diameter will be ans-1;   
    }
};