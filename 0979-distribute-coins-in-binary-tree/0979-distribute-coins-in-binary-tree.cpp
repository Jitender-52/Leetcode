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
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Distribute Coins in Binary Tree.
// Memory Usage: 15.5 MB, less than 5.69% of C++ online submissions for Distribute Coins in Binary Tree.
    
    int ans = 0;
    int solve(TreeNode *root)
    {
        if(!root)
            return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        ans += abs(l) + abs(r);
        return l + r + root->val - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        solve(root);
        return ans;
    }
};