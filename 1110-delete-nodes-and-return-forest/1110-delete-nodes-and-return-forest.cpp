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
    
//     Runtime: 16 ms, faster than 56.71% of C++ online submissions for Delete Nodes And Return Forest.
// Memory Usage: 27.1 MB, less than 23.69% of C++ online submissions for Delete Nodes And Return Forest.
    
    TreeNode *dfs(TreeNode *root, vector<int> &to_delete, vector<TreeNode *> &ans)
    {
        if(!root)
            return NULL;
        int n = to_delete.size();
        bool check = false;
        for(int i = 0; i < n; i++)
        {
            if(root->val == to_delete[i])
            {
                check = true;
            }
        }
        root->left = dfs(root->left, to_delete, ans);
        root->right = dfs(root->right, to_delete, ans);
        if(check)
        {
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode *> ans;
        if(dfs(root, to_delete, ans))
            ans.push_back(root);
        return ans;
    }
};