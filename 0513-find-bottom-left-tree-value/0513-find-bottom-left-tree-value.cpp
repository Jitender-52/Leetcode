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
   
//     Runtime: 3 ms, faster than 98.29% of C++ online submissions for Find Bottom Left Tree Value.
// Memory Usage: 20.2 MB, less than 76.07% of C++ online submissions for Find Bottom Left Tree Value.
    
//     Runtime: 7 ms, faster than 79.35% of C++ online submissions for Find Bottom Left Tree Value.
// Memory Usage: 20.3 MB, less than 63.53% of C++ online submissions for Find Bottom Left Tree Value.
    
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            ans = it->val;
            if(it->right)
                q.push(it->right);
            if(it->left)
                q.push(it->left);
        }
        return ans;
    }
};