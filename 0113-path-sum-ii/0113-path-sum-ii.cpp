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
    
    vector<vector<int>> ans;
    void solve(TreeNode *root, vector<int> &v, int sum, int &targetSum)
    {
        if(!root)
            return;
        sum += root->val;
        v.push_back(root->val);
        if(sum == targetSum && !root->left && !root->right)
            ans.push_back(v);
        solve(root->left, v, sum, targetSum);
        solve(root->right, v, sum, targetSum);
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        int sum = 0;
        solve(root, v, sum, targetSum);
        return ans;
    }
};