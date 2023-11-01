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
    
//     Runtime: 18 ms, faster than 46.52% of C++ online submissions for Find Mode in Binary Search Tree.
// Memory Usage: 26.1 MB, less than 15.27% of C++ online submissions for Find Mode in Binary Search Tree.

    
    map<int,int> mp;
    void dfs(TreeNode *root)
    {
        if(!root)
            return;
        mp[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        int maxi = 0;
        for(auto i : mp)
            maxi = max(maxi, i.second);
        vector<int> ans;
        for(auto i : mp)
        {
            if(i.second == maxi)
                ans.push_back(i.first);
        }
        return ans;
    }
};