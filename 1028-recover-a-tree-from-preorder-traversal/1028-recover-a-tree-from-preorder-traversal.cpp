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
    
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        map<int, TreeNode*> mp;
        int i = 0;
        while(i < n)
        {
            int count = 0;
            while(i < n && traversal[i] == '-')
            {
                count++;
                i++;
            }
            string s = "";
            while(i < n && traversal[i] >= '0' && traversal[i] <= '9')
            {
                s += traversal[i];
                i++;
            }
            int x = stoi(s);
            TreeNode *root = new TreeNode(x);
            if(count > 0)
            {
                if(!mp[count-1]->left)
                    mp[count-1]->left = root;
                else
                    mp[count-1]->right = root;
            }
            mp[count] = root;
        }
        return mp[0]; // i.e. root of the tree at zeroth level
    }
};

    

// God gifted solution to me

// Time complexity = O(N)
// Space Complexity = O(N)
    
//     Runtime: 32 ms, faster than 10.54% of C++ online submissions for Recover a Tree From Preorder Traversal.
// Memory Usage: 29.9 MB, less than 9.89% of C++ online submissions for Recover a Tree From Preorder Traversal.
    
//     TreeNode* recoverFromPreorder(string traversal) {
//         int n = traversal.size();
//         stack<TreeNode*> st;
//         map<TreeNode*, int> mp;
        
//         int i = 0;
//         TreeNode *root = new TreeNode(-1);
//         mp[root] = -1;
//         st.push(root);
//         while(i < n)
//         {
//             int count = 0;
//             while(i < n && traversal[i] == '-')
//             {
//                 count++;
//                 i++;
//             }
//             string s = "";
//             while(i < n && traversal[i] >= '0' && traversal[i] <= '9')
//             {
//                 s += traversal[i];
//                 i++;
//             }
//             int x = stoi(s);
//             // cout << x << " " << count << endl;
//             stack<TreeNode*> st1;
//             while(!st.empty())
//             {
//                 auto it = st.top();
//                 st.pop();
//                 // cout << it->val << endl;
//                 if(mp[it] == count-1)
//                 {
//                     st.push(it);
//                     if(!it->left)
//                     {
//                         it->left = new TreeNode(x);
//                         st.push(it->left);
//                         mp[it->left] = count;
//                     }
//                     else
//                     {
//                         it->right = new TreeNode(x);
//                         st.push(it->right);
//                         mp[it->right] = count;
//                     }
//                     break;
//                 }
//                 // st1.push(it);
//             }
//             // while(!st1.empty())
//             // {
//             //     cout << st1.top()->val << endl;
//             //     st.push(st1.top());
//             //     st1.pop();
//             // }
//         }
//         return root->left;
//     }
// };