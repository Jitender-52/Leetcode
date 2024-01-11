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
    
     void dfs(TreeNode *root, int maxi, int mini, int &ans)
    {
        if(!root)
            return;

        ans = max(ans, max(abs(mini - root->val), abs(maxi - root->val)));

        maxi = max(maxi, root->val);
        mini = min(mini, root->val);

        dfs(root->left, maxi, mini, ans);
        dfs(root->right, maxi, mini, ans);
    }

    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        dfs(root->left, maxi, mini, ans);
        dfs(root->right, maxi, mini, ans);
        return ans;
    }
};