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
    
        int minDepth(TreeNode* root) {
            queue<TreeNode *> q;
            if(root)
                q.push(root);
            int ans = 0;
            while(!q.empty())
            {
                ans++;
                int sz = q.size();
                for(int i = 0; i < sz; i++)
                {
                    auto it = q.front();
                    q.pop();
                    if(!it)
                        continue;
                    if(!it->left && !it->right)
                        return ans;
                    q.push(it->left);
                    q.push(it->right);
                }
            }
            return ans;
        }
};
    
    
//     Runtime: 290 ms, faster than 62.88% of C++ online submissions for Minimum Depth of Binary Tree.
// Memory Usage: 144.8 MB, less than 16.53% of C++ online submissions for Minimum Depth of Binary Tree.
    
//     int minDepth(TreeNode* root) {
//         if(!root)
//             return 0;
//         if(!root->left)
//             return 1 + minDepth(root->right);
//         if(!root->right)
//             return 1 + minDepth(root->left);
//         return 1 + min(minDepth(root->left), minDepth(root->right));   
//     }
// };