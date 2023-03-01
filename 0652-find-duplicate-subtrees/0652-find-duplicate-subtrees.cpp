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
    
        string duplicates(TreeNode *root, map<string, int> &mp, vector<TreeNode *> &ans)
        {
            if(!root)
                return "*";
            string left = duplicates(root->left, mp, ans);
            string right = duplicates(root->right, mp, ans);
            string s = left + "*" + right + "*" + to_string(root->val);
            if(mp[s] == 1)
            {
                ans.push_back(root);
            }
            mp[s]++;
            return s;
        }

        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
            map<string,int> mp;
            vector<TreeNode *> ans;
            duplicates(root, mp, ans);
            return ans;
        } 
};
    
    
//     Runtime: 28 ms, faster than 75.69% of C++ online submissions for Find Duplicate Subtrees.
// Memory Usage: 36.5 MB, less than 77.18% of C++ online submissions for Find Duplicate Subtrees.
    

    // Just copy paste for streak
    
//     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//         unordered_map<string, int> cnt;
//         vector<TreeNode*> res;
//         function<string(TreeNode*)> traverse = [&cnt, &res, &traverse](TreeNode* node) -> string {
//             if (node == nullptr) {
//                 return "";
//             }
//             string representation = "(" + traverse(node->left) + ")" + to_string(node->val) + "(" +
//                                     traverse(node->right) + ")";
//             cnt[representation]++;
//             if (cnt[representation] == 2) {
//                 res.push_back(node);
//             }
//             return representation;
//         };
//         traverse(root);
//         return res;
//     }
// };