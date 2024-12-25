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
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Largest Value in Each Tree Row.
// Memory Usage: 22.7 MB, less than 26.80% of C++ online submissions for Find Largest Value in Each Tree Row.
    
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode *> q;
        if(root)
            q.push(root);
        vector<int> ans;
        while(!q.empty())
        {
            int maxi = INT_MIN, sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto it = q.front();
                q.pop();
                maxi = max(maxi, it->val);
                if(it->left)
                    q.push(it->left);
                if(it->right)  
                    q.push(it->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};