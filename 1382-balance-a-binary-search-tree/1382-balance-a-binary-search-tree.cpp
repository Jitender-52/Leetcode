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
    
//     Runtime: 88 ms, faster than 64.41% of C++ online submissions for Balance a Binary Search Tree.
// Memory Usage: 62.6 MB, less than 40.07% of C++ online submissions for Balance a Binary Search Tree.
    
    void dfs(TreeNode *root, vector<int> &v)
    {
        if(!root)
            return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
    
    TreeNode *build(int l, int r, vector<int> &v)
    {
        if(l > r)
            return NULL;
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(v[mid]);
        root->left = build(l, mid-1, v);
        root->right = build(mid+1, r, v);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        dfs(root, v);
        return build(0, v.size()-1, v);
    }
};