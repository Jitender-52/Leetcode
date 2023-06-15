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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0, sum = INT_MIN, level = 1;
        while(!q.empty())
        {
            int sz = q.size();
            int count = 0;
            for(int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                count += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(count > sum)
            {
                sum = count;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};