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
    
//     Runtime: 4 ms, faster than 42.65% of C++ online submissions for Reverse Odd Levels of Binary Tree.
// Memory Usage: 84.1 MB, less than 13.13% of C++ online submissions for Reverse Odd Levels of Binary Tree.
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode *> q;
        
        if(root)
        {
            q.push(root);
            // v.push_back(root);
        }
        
        int count = 0;
        while(!q.empty())
        {
            vector<TreeNode *> v;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left)
                {
                    q.push(temp->left);
                    v.push_back(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                    v.push_back(temp->right);
                }
            }
            
            if(count % 2 == 0)
            {
                int p = v.size();
                // cout << p << endl;
                for(int i = 0; i < p/2; i++)
                {
                    TreeNode *a = v[i];
                    TreeNode *b = v[p-1-i];
                    int temp = a->val;
                    a->val = b->val;
                    b->val = temp;
                    // swap(a->val, b->val);
                    // swap(v[i]->val, v[p-1-i]->val);
                    // int temp = v[i]->val;
                    // v[i]->val = v[n-1-i]->val;
                    // v[n-1-i]->val = temp;
                }
            }
            count++;
        }
        return root;
    }
};
    
//     TreeNode* reverseOddLevels(TreeNode* root) {
//         queue<TreeNode *> q;
        
//         if(root)
//         {
//             q.push(root);
//             // v.push_back(root);
//         }
        
//         int count = 0;
//         while(!q.empty())
//         {
//             vector<TreeNode *> v;
//             int n = q.size();
//             for(int i = 0; i < n; i++)
//             {
//                 TreeNode *temp = q.front();
//                 q.pop();
//                 if(temp->left)
//                 {
//                     q.push(temp->left);
//                     v.push_back(temp->left);
//                 }
//                 if(temp->right)
//                 {
//                     q.push(temp->right);
//                     v.push_back(temp->right);
//                 }
//             }
            
//             if(count % 2 == 1)
//             {
//                 int p = v.size();
//                 // cout << p << endl;
//                 for(int i = 0; i < p/2; i++)
//                 {
//                     TreeNode *a = v[i];
//                     TreeNode *b = v[p-1-i];
//                     int temp = a->val;
//                     a->val = b->val;
//                     b->val = temp;
//                     // swap(a->val, b->val);
//                     // swap(v[i]->val, v[p-1-i]->val);
//                     // int temp = v[i]->val;
//                     // v[i]->val = v[n-1-i]->val;
//                     // v[n-1-i]->val = temp;
//                 }
//             }
//             count++;
//         }
//         return root;
//     }
// };