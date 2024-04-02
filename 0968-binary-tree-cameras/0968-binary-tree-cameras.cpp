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
    
//     Thought of the day debugging is much more greater than solving and accepted solution
//     Debugging >>>>> solving, accepted
//     Can be solved easily with the map but debugging gave the easiest way without any extra space
    
    map<TreeNode*, int> mp;
    int ans = 0;
    
// 0->means child also require camera
// 1->means child does not need camera
// 2->means child have camera
    
    int solve(TreeNode *root)
    {
        if(!root)
            return 1;
        if(!root->left && !root->right)
            return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        if(l == 0 || r == 0)
        {
            ans++;
            return 2;
        }
        if(l == 2 || r == 2)
            return 1;
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        if(!solve(root))
            ans++; // root does not have any camera
        return max(1, ans); // atleast one camera is needed in case of single node it will zero so either use the condition or use this.
    }
};

// [0,0,null,0,0]
// [0,0,null,0,null,0,null,null,0]
// [0]
// [0,0,null,null,0,0,null,null,0,0]
// [0,null,0,null,0,null,0]