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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        
        bool check = true;
        vector<vector<int>> ans;
        while(!q.empty())
        {
            vector<int> v;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                v.push_back(temp->val);
                // if(check)
                // {
                    // cout << "HII" << endl;
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                // }
                // else
                // {
                //     // cout << "BYE" << endl;
                //     if(temp->right)
                //         q.push(temp->right);
                //     if(temp->left)
                //         q.push(temp->left);
                // }
            }
        
            if(!check)
                reverse(v.begin(), v.end());
        
            // cout << endl;
            ans.push_back(v);
            check = !check;
        }
        return ans;
    }
};