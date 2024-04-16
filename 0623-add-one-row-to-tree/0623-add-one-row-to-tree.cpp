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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode *newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(depth > 1)
        {
            int sz = q.size();
            depth--;
            for(int i = 0; i < sz; i++)
            {
                auto node = q.front();
                q.pop();
                if(depth == 1)
                {
                    TreeNode *l = new TreeNode(val);
                    TreeNode *r = new TreeNode(val);
                    l->left = node->left;
                    node->left = l;
                    r->right = node->right;
                    node->right = r;
                }
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                }
        }
        return root;
    }
};