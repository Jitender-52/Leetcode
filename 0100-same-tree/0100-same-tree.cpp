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
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Same Tree.
// Memory Usage: 10.2 MB, less than 8.85% of C++ online submissions for Same Tree.
    
    
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
     if (!root1 && !root2)
        return true;
    if (!root1 || !root2 || root1->val != root2->val)
        return false;

    if(isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right))
        return true;
    return false;   
    }
};