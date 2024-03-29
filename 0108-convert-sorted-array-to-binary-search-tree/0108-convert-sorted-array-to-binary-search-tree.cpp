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
    
    TreeNode *bst(vector<int> &nums, int left, int right)
    {
        if(left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = bst(nums, left, mid-1);
        root->right = bst(nums, mid+1, right);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return bst(nums, 0, n-1);
    }
};
    
    
    
//     Runtime: 17 ms, faster than 46.58% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// Memory Usage: 21.5 MB, less than 49.46% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
    
//     TreeNode *bst(vector<int> &nums, int left, int right)
//     {
//         if(left > right)
//             return NULL;
//         int mid = (left + right) / 2;
//         TreeNode *root = new TreeNode(nums[mid]);
//         root->left = bst(nums, left, mid-1);
//         root->right = bst(nums, mid+1, right);
//         return root;
//     }
    
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         int n = nums.size();
//         TreeNode *root = new TreeNode(nums[n/2]);
//         root->left = bst(nums, 0, n/2 - 1);
//         root->right = bst(nums, n/2+1, n-1);
//         return root;
//     }
// };