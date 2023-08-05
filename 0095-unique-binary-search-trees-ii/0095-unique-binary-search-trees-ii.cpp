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
    
    
//     Runtime: 20 ms, faster than 55.14% of C++ online submissions for Unique Binary Search Trees II.
// Memory Usage: 15.5 MB, less than 87.54% of C++ online submissions for Unique Binary Search Trees II.
    
    
    vector<TreeNode *> generate(int l, int r)
    {
        vector<TreeNode *> ans;
        if(l < 1 || l > r)
        {
            ans.push_back(NULL);
            return ans;
        }
        
        if(l == r)
        {
            TreeNode *temp = new TreeNode(l);
            // temp->left = NULL; // can work without these as default are NULL
            // temp->right = NULL;
            ans.push_back(temp);
            return ans;
        }
        
        for(int i = l; i <= r; i++)
        {
            // TreeNode *temp = new TreeNode(i);  // If we use it here instead of downward nested loops then it gives wrong answer
            
            vector<TreeNode *> lt = generate(l, i-1);
            vector<TreeNode *> rt = generate(i+1, r);
            
            for(int j = 0; j < lt.size(); j++)
            {
                for(int k = 0; k < rt.size(); k++)
                {
                    TreeNode *temp = new TreeNode(i);
                    temp->left = lt[j];
                    temp->right = rt[k];
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
        
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};