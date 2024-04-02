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
    
    // map<TreeNode*, int> mp;
    set<TreeNode *> st;
    int ans = 0;
    
    void solve(TreeNode *root, TreeNode *parent)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
            return;
        solve(root->left, root);
        solve(root->right, root);
        if((!root->left || st.find(root->left) != st.end()) && (!root->right || st.find(root->right) != st.end()))
            return;
        else
        {
            ans++;
            st.insert(root);
            if(root->left)
                st.insert(root->left);
            if(root->right)
                st.insert(root->right);
            st.insert(parent);
        }
    }
    
    int minCameraCover(TreeNode* root) {
        solve(root, root);
        return ans + (st.find(root) == st.end());
    }
};
    
    
//     Runtime: 7 ms, faster than 64.11% of C++ online submissions for Binary Tree Cameras.
// Memory Usage: 20 MB, less than 58.79% of C++ online submissions for Binary Tree Cameras.
    
//     Thought of the day debugging is much more greater than solving and accepted solution
//     Debugging >>>>> solving, accepted
//     Can be solved easily with the map but debugging gave the easiest way without any extra space
    



// Best Solution in O(1) space complexity --> Even Not in the leetcode solution also 

//     map<TreeNode*, int> mp;
//     int ans = 0;
    
// // 0->means child also require camera
// // 1->means child does not need camera
// // 2->means child have camera
    
//     int solve(TreeNode *root)
//     {
//         if(!root)
//             return 1;
//         if(!root->left && !root->right)
//             return 0;
//         int l = solve(root->left);
//         int r = solve(root->right);
//         if(l == 0 || r == 0)
//         {
//             ans++;
//             return 2;
//         }
//         if(l == 2 || r == 2)
//             return 1;
//         return 0;
//     }
    
//     int minCameraCover(TreeNode* root) {
//         if(!solve(root))
//             ans++; // root does not have any camera
//         return max(1, ans); // atleast one camera is needed in case of single node it will zero so either use the condition or use this.
//     }
// };



// [0,0,null,0,0]
// [0,0,null,0,null,0,null,null,0]
// [0]
// [0,0,null,null,0,0,null,null,0,0]
// [0,null,0,null,0,null,0]