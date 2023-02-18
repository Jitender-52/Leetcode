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
    TreeNode* invertTree(TreeNode* root) {
        
        queue<TreeNode *> q;
        if(root)
            q.push(root);
        
        while(!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            TreeNode *temp = front->left;
            front->left = front->right;
            front->right = temp;
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        return root;   
    }
};