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
    
//     Runtime: 4 ms, faster than 39.59% of C++ online submissions for Binary Search Tree to Greater Sum Tree.
// Memory Usage: 8.5 MB, less than 73.60% of C++ online submissions for Binary Search Tree to Greater Sum Tree.
    
     void convertTree(TreeNode* &root, int &sum) 
     {
        if (root == NULL) 
            return;
        convertTree(root->left, sum);
        int currNodeVal = root->val;
        root->val = sum;
        sum-=currNodeVal;
        convertTree(root->right, sum);
    }

    int totalSum(TreeNode* root) 
    {
        if (root == NULL)
            return 0;
        return totalSum(root->left) + root->val + totalSum(root->right);
    }


    TreeNode* bstToGst(TreeNode* root) {
        int nodeSum = totalSum(root);
        convertTree(root, nodeSum);
        return root;
    }
};