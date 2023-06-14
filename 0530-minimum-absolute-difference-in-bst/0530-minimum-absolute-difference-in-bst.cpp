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
    
        int dfs(TreeNode *root, TreeNode *&prev)
        {
            if(!root)
                return 1e6;
            int ans = dfs(root->left, prev);
            
            if(prev)
                ans = min(ans, abs(root->val - prev->val));
            
            prev = root;
            ans = min(ans, dfs(root->right, prev));
            return ans;
        }
    
        int getMinimumDifference(TreeNode* root) {
            TreeNode *prev = NULL;
            return dfs(root, prev);
        }
};
    
    
    
    // int dfs(TreeNode *root)
    // {
    //     int ans = INT_MAX;
    //     if(root->left)
    //     {
    //         ans = min(ans, abs(root->val - root->left->val));
    //         ans = min(ans, dfs(root->left));
    //     }
    //     if(root->right)
    //     {
    //         ans = min(ans, abs(root->val - root->right->val));
    //         ans = min(ans, dfs(root->right));
    //     }
    //     return ans;
    // }
    
//     int dfs(TreeNode *root, int mini, int maxi)
//     {
//         if(!root)
//             return 1e5;
//         int ans = min(abs(root->val - mini), abs(maxi - root->val));
//         if(root->left)
//         {
//             ans = min(ans, abs(root->left->val - root->val));
//         }
//         if(root->right)
            
//         {
//             ans = min(ans, abs(root->right->val - root->val));
//         }
//         mini = min(mini, root->val);
//         maxi = max(maxi, root->val);
//         ans = min(ans, min(dfs(root->left, mini, maxi), dfs(root->right, mini, maxi)));
//         return ans;
//     }
    
//     int getMinimumDifference(TreeNode* root) {
//         return dfs(root, 1e6, - 1e6);
//     }
// };