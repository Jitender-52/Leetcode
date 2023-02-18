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
        
        void dfs(TreeNode* &root)
        {
            if(!root)
                return;
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
            dfs(root->left);
            dfs(root->right);
        }
    
        TreeNode* invertTree(TreeNode* root) {
            dfs(root);
            return root;
        }
};
    
    
    
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
// Memory Usage: 9.8 MB, less than 7.06% of C++ online submissions for Invert Binary Tree.

    
//     TreeNode* invertTree(TreeNode* root) {
        
//         queue<TreeNode *> q;
//         if(root)
//             q.push(root);
        
//         while(!q.empty())
//         {
//             TreeNode *front = q.front();
//             q.pop();
//             TreeNode *temp = front->left;
//             front->left = front->right;
//             front->right = temp;
//             if(front->left)
//                 q.push(front->left);
//             if(front->right)
//                 q.push(front->right);
//         }
//         return root;   
//     }
// };