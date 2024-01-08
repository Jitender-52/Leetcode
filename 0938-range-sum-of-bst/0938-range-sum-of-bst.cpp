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
    
//     Runtime: 102 ms, faster than 42.94% of C++ online submissions for Range Sum of BST.
// Memory Usage: 65 MB, less than 25.88% of C++ online submissions for Range Sum of BST.
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        
        int ans = 0;
        if(root->val >= low && root->val <= high)
            ans = root->val;        
        
        if(root->val >= low)
            ans += rangeSumBST(root->left, low, high);
        if(root->val <= high)
            ans += rangeSumBST(root->right, low, high);
        return ans;
    }
};