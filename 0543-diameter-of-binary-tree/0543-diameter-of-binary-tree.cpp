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
    
    int ans = 0;
    int diameter(TreeNode *root)
    {
        if(!root)
            return 0;
        int l = diameter(root->left);
        int r = diameter(root->right);
        ans =  max(ans, (l + r + 1));
        return max(l, r) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return ans - 1; // Here ans is the number of nodes so diameter will be ans - 1;
    }
};