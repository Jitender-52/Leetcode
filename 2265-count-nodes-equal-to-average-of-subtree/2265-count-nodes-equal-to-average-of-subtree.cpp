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
    pair<int, int> solve(TreeNode *root)
    {
        if(!root)
            return {0, 0};
        auto l = solve(root->left);
        auto r = solve(root->right);
        if(l.second + r.second == 0 || (l.first + r.first + root->val) / (l.second + r.second + 1) == root->val)
            ans++;
        return {l.first + r.first + root->val, l.second + r.second + 1};
    }
    
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};