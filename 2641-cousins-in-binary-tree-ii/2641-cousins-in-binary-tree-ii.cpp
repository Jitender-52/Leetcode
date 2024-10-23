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
    
//     Runtime: 138 ms, faster than 91.98% of C++ online submissions for Cousins in Binary Tree II.
// Memory Usage: 487.3 MB, less than 5.57% of C++ online submissions for Cousins in Binary Tree II.
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        root->val = 0;
        while(!q.empty())
        {
            int n = q.size();
            queue<TreeNode *> q1;
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                auto it = q.front();
                q.pop();
                q1.push(it);
                if(it->left)
                {
                    sum += it->left->val;
                    q.push(it->left);
                }
                if(it->right)
                {
                    sum += it->right->val;
                    q.push(it->right);
                }
            }
            for(int i = 0; i < n; i++)
            {
                auto it = q1.front();
                q1.pop();
                int sum2 = 0;
                if(it->left)
                    sum2 += it->left->val;
                if(it->right)
                    sum2 += it->right->val;
                if(it->left)
                    it->left->val = sum - sum2;
                if(it->right)
                    it->right->val = sum - sum2;
            }
        }
        return root;
    }
};