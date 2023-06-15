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
    
    void dfs(TreeNode *root, int level, vector<int> &v)
    {
        if(!root)
            return;
        if(v.size() == level)
            v.push_back(root->val);
        else
            v[level] += root->val;
        dfs(root->left, level + 1, v);
        dfs(root->right, level + 1, v);
    }
        
    
    int maxLevelSum(TreeNode* root) {
        vector<int> v;
        dfs(root, 0, v);
        int sum = INT_MIN, ans = 0; // mybad used sum = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] > sum)
            {
                sum = v[i];
                ans = i+1;
            }
        }
        return ans;
    }
};
    
    
//     Runtime: 180 ms, faster than 97.63% of C++ online submissions for Maximum Level Sum of a Binary Tree.
// Memory Usage: 107.2 MB, less than 59.25% of C++ online submissions for Maximum Level Sum of a Binary Tree.
    
//     int maxLevelSum(TreeNode* root) {
//         queue<TreeNode *> q;
//         q.push(root);
//         int ans = 0, sum = INT_MIN, level = 1;
//         while(!q.empty())
//         {
//             int sz = q.size();
//             int count = 0;
//             for(int i = 0; i < sz; i++)
//             {
//                 TreeNode *node = q.front();
//                 q.pop();
//                 count += node->val;
//                 if(node->left)
//                     q.push(node->left);
//                 if(node->right)
//                     q.push(node->right);
//             }
//             if(count > sum)
//             {
//                 sum = count;
//                 ans = level;
//             }
//             level++;
//         }
//         return ans;
//     }
// };