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
    
    vector<vector<int>> adj;
    
    void dfs(TreeNode *root)
    {
        if(!root)
            return;
        if(root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        dfs(root->left);
        dfs(root->right);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        adj.resize(1e5 + 1);
        dfs(root);
        queue<int> q;
        vector<int> vis(1e5+1, 0);
        q.push(start);
        vis[start] = 1;
        int ans = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int j = 0; j < sz; j++)
            {
                int node = q.front();
                q.pop();
                for(auto i : adj[node])
                {
                    if(!vis[i])
                    {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
            ans++;
        }
        return ans-1;
    }
};