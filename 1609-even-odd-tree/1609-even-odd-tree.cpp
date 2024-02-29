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
    
//     Runtime: 190 ms, faster than 85.12% of C++ online submissions for Even Odd Tree.
// Memory Usage: 149.2 MB, less than 76.25% of C++ online submissions for Even Odd Tree.
    
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int x = 1;
        while(!q.empty())
        {
            int sz = q.size();
            int a = 0;
            if(!x)
                a = 1e6 + 1;
            for(int i = 0; i < sz; i++)
            {
                auto it = q.front();
                q.pop();
                if(!x && (a <= it->val || (it->val % 2 == 1)))
                    return false;
                if(x && (a >= it->val || (it->val % 2 != 1)))
                    return false;
                a = it->val;
                if(it->left)
                    q.push(it->left);
                if(it->right)
                    q.push(it->right);
            }
            x ^= 1;
        }
        return true;
    }
};