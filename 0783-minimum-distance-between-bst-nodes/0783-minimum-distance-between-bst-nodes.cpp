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

    
    void inorder(TreeNode *root, int &mini, TreeNode* &prev)
    {
        if(!root)
            return;
        
        inorder(root->left, mini, prev);
        if(prev)
            mini = min(mini, root->val - prev->val);
        prev = root;
        inorder(root->right, mini, prev);
    }
    
    int minDiffInBST(TreeNode* root) {
        int mini = INT_MAX;
        TreeNode *prev = NULL;
        inorder(root, mini, prev);
        return mini;
    }
};
    
//         int minDiffInBST(TreeNode* root) {
//             return 1;
//         }
// };

         //    27
         //  /    \
         // n      34
         //           \
         //            58
         //            / \
         //           50  n
         //          /
         //         44
    
    
//     Runtime: 4 ms, faster than 56.01% of C++ online submissions for Minimum Distance Between BST Nodes.
// Memory Usage: 10 MB, less than 6.62% of C++ online submissions for Minimum Distance Between BST Nodes.

    
    
//     void dfs(TreeNode *root, vector<int> &v)
//     {
//         if(!root)
//             return;
        
//         v.push_back(root->val);
//         dfs(root->left, v);
//         dfs(root->right, v);
        
//         // if(root->left)
//         //     mini = min(root->val - root->left->val, mini);
//         // if(root->right)
//         //     mini = min(root->right->val - root->val, mini);
//         // dfs(root->left, mini);
//         // dfs(root->right, mini);
//     }
    
//     int minDiffInBST(TreeNode* root) {
//         int mini = INT_MAX;
//         vector<int> v;
//         dfs(root, v);
//         sort(v.begin(), v.end());
//         for(int i = 1; i < v.size(); i++)
//         {
//             mini = min(mini, v[i] - v[i-1]);
//         }
//         return mini;
//     }
// };