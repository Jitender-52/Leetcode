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
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Leaf-Similar Trees.
// Memory Usage: 13.3 MB, less than 30.37% of C++ online submissions for Leaf-Similar Trees.
    
    void dfs(TreeNode *root, vector<int> &v)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            v.push_back(root->val);
            return;
        }
        dfs(root->left, v);
        dfs(root->right, v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        dfs(root1, v1);
        dfs(root2, v2);
        if(v1 == v2)
            return true;
        return false;
    }
};