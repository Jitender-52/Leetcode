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

vector<vector<pair<int,int>>> adj(1e5+1);

class Solution {
public:

    bool solve(TreeNode *root, int val, string &s)
    {
        if(root->val == val)
            return true;
        if(root->left && solve(root->left, val, s))
            s += 'L';
        else if(root->right && solve(root->right, val, s))
            s += 'R';
        return s != "";
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s = "", p = "";
        solve(root, startValue, s);
        solve(root, destValue, p);
        while(!s.empty() && !p.empty() && s.back() == p.back())
        {
            s.pop_back();
            p.pop_back();
        }
        reverse(p.begin(), p.end());
        return string(s.size(), 'U') + p; 
    }
};
    
    
//     string ans;
    
//     void solve(TreeNode *root, int par)
//     {
//         if(par != -1)
//             adj[root->val].push_back({par, 0});
//         if(!root)
//             return;
//         if(root->left)
//         {
//             adj[root->val].push_back({root->left->val, 1});
//             solve(root->left, root->val);
//         }
//         if(root->right)
//         {
//             adj[root->val].push_back({root->right->val, 2});
//             solve(root->right, root->val);
//         }
//     }
    
//     void solve2(int src, int last, int destValue, string &s)
//     {
//         if(src == destValue)
//         {
//             ans = s;
//             return;
//         }
//         for(auto i : adj[src])
//         {
//             if(i.first != last)
//             {
//                 if(i.second == 0)
//                     s += 'U';
//                 else if(i.second == 1)
//                     s += 'L';
//                 else
//                     s += 'R';
//                 solve2(i.first, src, destValue, s);
//                 s.pop_back();
//             }
//         }
//     }
    
//     string getDirections(TreeNode* root, int startValue, int destValue) {
//         solve(root, -1);
//         string s = "";
//         solve2(startValue, -1, destValue, s);
//         return ans;
//     }
// };