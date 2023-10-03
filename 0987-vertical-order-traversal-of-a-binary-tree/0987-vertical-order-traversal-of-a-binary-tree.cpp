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
    
    void dfs(TreeNode *root, int idx, int hz, map<int, vector<pair<int,int>>> &mp)
    {
        if(!root)
            return;
        mp[idx].push_back({root->val, hz});
        dfs(root->left, idx - 1, hz + 1, mp);
        dfs(root->right, idx + 1, hz + 1, mp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int idx = 0, hz = 0;
        map<int, vector<pair<int,int>>> mp;
        dfs(root, idx, hz, mp);
        
        vector<vector<int>> ans;
        for(auto &i : mp)
        {
            vector<int> v;
            sort(i.second.begin(), i.second.end(), [&](const pair<int,int> &a, const pair<int,int> &b){
               if(a.second == b.second)
                   return a.first <= b.first;
                return a.second < b.second;
            });
            for(auto j : i.second)
                v.push_back(j.first);
            ans.push_back(v);
        }
        return ans;
    }
};