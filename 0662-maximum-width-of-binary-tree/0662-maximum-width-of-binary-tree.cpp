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
    
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)return 0;
        queue<pair<TreeNode*, unsigned long long int>> que;
        que.push({root, 0});
        int width = 0;
        while (que.size() != 0) {
            unsigned long long int left = que.front().second, right = 0;
            int size = que.size();
            while (size-- > 0) {
                pair<TreeNode*, unsigned long long int> rNode = que.front();
                que.pop();
                right = rNode.second;
                if (rNode.first->left) {
                    que.push({rNode.first->left, 2 * rNode.second + 1});
                }
                if (rNode.first->right) {
                    que.push({rNode.first->right, 2 * rNode.second + 2});
                }
            }
            width = max(width, int(right - left + 1));
        }
        return width;
    }
};
    
    
    
//      long long maxVal = 0;
//     unordered_map<long long,long long> levelLeft;
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         dfs(root, 0, 0);
//         return maxVal;
//     }

//     void dfs(TreeNode* root, long long depth, long long pos) 
//     {
//         if (root == NULL) 
//             return;
        
//         if (levelLeft.find(depth)==levelLeft.end())
//            levelLeft[depth]=pos;
        
//         maxVal = max(maxVal, pos - levelLeft[depth] + 1);
        
//         dfs(root->left, depth + 1, 2 * pos); //make sure all left explored first using dfs
//         dfs(root->right, depth + 1, 2 * pos + 1);
//     }
// };
    
    
//     int widthOfBinaryTree(TreeNode* root) {
//         queue<TreeNode *> q;
//         if(root)
//             q.push(root);
        
//         int ans = 0;
//         while(!q.empty())
//         {
//             int count = 0;
//             int mini = 1e9;
//             int n = q.size();
//             for(int i = 0; i < n; i++)
//             {
//                 auto temp = q.front();
//                 q.pop();
//                 if(mini == 1e9 && temp != NULL)
//                 {
//                     mini = 0;
//                 }
//                 count++;
//                 if(temp != NULL)
//                 {
//                     ans = max(ans, count - mini);
//                 }
//                 if(temp && temp->left)
//                     q.push(temp->left);
//                 else
//                     q.push(NULL);
//                 if(temp && temp->right)
//                     q.push(temp->right);
//                 else
//                     q.push(NULL);
//             }
            
//             if(mini == 1e9)
//                 break;
//         }
//         return ans;
//     }
// };