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
    
//     Runtime: 225 ms, faster than 98.12% of C++ online submissions for Pseudo-Palindromic Paths in a Binary Tree.
// Memory Usage: 177.7 MB, less than 98.93% of C++ online submissions for Pseudo-Palindromic Paths in a Binary Tree.
    
    vector<int> v;
    int ans = 0;
    
    void solve(TreeNode *root)
    {
        if(!root)
            return;
        v[root->val]++;
        int check = 0;
        for(int i = 1; i < 10; i++)
        {
            check += v[i] % 2;  
        }
        if(check < 2 && !root->left && !root->right)
            ans++;
        solve(root->left);
        solve(root->right);
        v[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        v.resize(10);
        solve(root);
        return ans;
    }
};