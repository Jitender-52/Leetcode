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
    
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int> st;
        map<int, TreeNode*> mp;
        for(auto v : descriptions)
        {
            int a = v[0], b = v[1], c = v[2];
            if(mp.find(a) == mp.end())
            {
                TreeNode *t = new TreeNode(a);
                mp[a] = t;
            }
            if(mp.find(b) == mp.end())
            {
                TreeNode *t = new TreeNode(b);
                mp[b] = t;
            }
            if(c)
                mp[a]->left = mp[b];
            else
                mp[a]->right = mp[b];
            st.insert(a);
            st.insert(b);
        }
        for(auto v : descriptions)
        {
            if(st.find(v[1]) != st.end())
                st.erase(v[1]);
        }
        return mp[*st.begin()];
    }
};