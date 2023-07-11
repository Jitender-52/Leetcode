/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void makeParent(TreeNode *root, map<TreeNode *, TreeNode *> &parent)
    {
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            if(temp->left)
            {
                parent[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode *, TreeNode *> parent;
        makeParent(root, parent);
        
        queue<TreeNode *> q;
        q.push(target);
        map<TreeNode *, bool> vis;
        vis[target] = true;
        int level = 0;
        while(!q.empty())
        {
            if(level == k)
                break;
            
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto temp = q.front();
                q.pop();
                if(temp->left && !vis[temp->left])
                {
                    q.push(temp->left);
                    vis[temp->left] = true;
                }
                if(temp->right && !vis[temp->right])
                {
                    q.push(temp->right);
                    vis[temp->right] = true;
                }
                if(parent[temp] && !vis[parent[temp]])
                {
                    q.push(parent[temp]);
                    vis[parent[temp]] = true;
                }
            }
            level++;
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;        
    }
};