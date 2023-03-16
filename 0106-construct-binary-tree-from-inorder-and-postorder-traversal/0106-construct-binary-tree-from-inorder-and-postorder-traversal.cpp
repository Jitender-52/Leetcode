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
    
    int search(int start, int end, vector<int> &inorder, int val)
    {
        for(int i = start; i <= end; i++)
        {
            if(inorder[i] == val)
                return i;
        }
        return -1;
    }
    
    TreeNode *build(int &idx, int start, int end, vector<int> &inorder, vector<int> &postorder)
    {
        if(start > end)
            return NULL;
        int val = postorder[idx];
        TreeNode *root = new TreeNode(val);
        idx--;
        if(start == end)
            return root;
        int pos = search(start, end, inorder, val);
        
        root->right = build(idx, pos+1, end, inorder, postorder);
        root->left = build(idx, start, pos-1, inorder, postorder);
        return root;
    }
        
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size() - 1;
        return build(idx, 0, inorder.size() - 1, inorder, postorder);
    }
};