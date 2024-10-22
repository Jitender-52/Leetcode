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
    
        vector<long long> sum;
    
        void dfs(TreeNode *root, int level)
        {
            if(!root)
                return;
            
            if(sum.size() <= level)
            {
                sum.push_back(root->val);
            }
            else 
            {
                sum[level] += root->val; 
            }
            
            dfs(root->left, level+1);
            dfs(root->right, level+1);
        }
    
        long long kthLargestLevelSum(TreeNode* root, int k) {
            sum.clear();
            dfs(root, 0);
            sort(sum.rbegin(), sum.rend());
            if(sum.size() < k)
                return -1;
            return sum[k-1];
        }
};
    
    
    
//     long long kthLargestLevelSum(TreeNode* root, int k) {
//         vector<long long> v;
    
//         queue<TreeNode *> q;
//         if(root)
//             q.push(root);
//         while(!q.empty())
//         {
//             int n = q.size();
//             long long sum = 0;
//             for(int i  =0; i < n; i++)
//             {
//                 TreeNode *temp = q.front();
//                 q.pop();
//                 sum += temp->val;
//                 if(temp->left)
//                     q.push(temp->left);
//                 if(temp->right)
//                     q.push(temp->right);
//             }
//             v.push_back(sum);
//         }
//         sort(v.rbegin(), v.rend());
        
//         // for(int i = 0; i < v.size(); i++)
//         // {
//         //     cout << v[i] <<" ";
//         // }
//         // cout << endl;
        
//         if(v.size() < k)
//             return -1;
//         return v[k-1];
//     }
    
// };