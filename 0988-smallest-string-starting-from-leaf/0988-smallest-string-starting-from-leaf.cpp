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
        
    string smallestString;
    
    void dfs(TreeNode* root, string currentString) 
    {
        if (!root)
            return;

        currentString = char(root->val + 'a') + currentString; 

        if (!root->left && !root->right) 
        { 
            if (smallestString == "" || smallestString > currentString)
                smallestString = currentString;
        }

        if (root->left) 
            dfs(root->left, currentString);
        if (root->right) 
            dfs(root->right, currentString);
    }
        
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return smallestString;
    }
};
    
//     string ans = "{";
    
//     string smallest(string s, string t)
//     {
//         if(s.length() <= 1)
//             return t;
//         if(t == "{")
//             return s;
//         if(s < t)
//             return s;
//         return t;
//     }
    
//     void solve(TreeNode *root, string s)
//     {
//         if(!root)
//         {
//             ans = smallest(s, ans);
//             return;
//         }
//         s = char('a' + root->val) + s;
//         solve(root->left, s);
//         solve(root->right, s);
//     }
        
//     string smallestFromLeaf(TreeNode* root) {
//         string s = "";
//         solve(root, s);
//         if(ans == "{")
//         {
//             ans = "";
//             ans += ('a' + root->val);
//         }
//         return ans;
//     }
// };
    

// [0,1,2,3,4,3,4]
// [25,1,3,1,3,0,2]
// [2,2,1,null,1,0,null,0]
// [25,1,null,0,0,1,null,null,null,0]
// [0,null,1]
    
    
    // Cannot Solve in this way, go and debug for the testcase 69 will get why it will fail
    
//     string smallest(string s, string t)
//     {
//         if(s < t)
//             return s;
//         return t;
//     }
        
//     string smallestFromLeaf(TreeNode* root) {
//         if(!root)
//             return "{";
//         string x = "";
//         x += 'a' + root->val;
//         if(!root->left && !root->right)
//             return x;
//         string s = "{", t = "{";
//         if(root->left)
//         {
//             s = "";
//             s += smallestFromLeaf(root->left);
//             // cout << "s = " << s << endl;
//             s += x;
//         }
//         if(root->right)
//         {
//             t = "";
//             t += smallestFromLeaf(root->right);
//             // cout << "t = " << t << endl;
//             t += x;
//         }
//         string ans = smallest(s, t);
//         // cout << root->val << " " << s << " " << t << " " << ans << endl;
//         return ans;
//     }
// };
    
    
    
//     string smallest(string &s, string &t)
//     {
//         if(s < t)
//             return s;
//         return t;
// //         int n = s.length(), m = t.length();
// //         if(m == 1)
// //             return s;
// //         if(n == 1)
// //             return t;
// // //         These two conditions are for if either of one(left, right) exists only because in that case we need to consider the path that have string but if we were adding the root value later after comparing then answer was coming wrong on testcase 67 and show we added the root value before comapring, so string will have size of 1 always(i.e root value).
// //         for(int i = 0; i < min(n, m); i++)
// //         {
// //             if(s[i] < t[i])
// //                 return s;
// //             if(t[i] < s[i])
// //                 return t;
// //         }
// //         if(n < m)
// //             return s;
// //         return t;
//     }
        
//     string smallestFromLeaf(TreeNode* root) {
//         if(!root)
//             return "{";
//         string x = "";
//         x += 'a' + root->val;
//         if(!root->left && !root->right)
//             return x;
//         string s = smallestFromLeaf(root->left);
//         string t = smallestFromLeaf(root->right);
//         s += char('a' + root->val);
//         t += char('a' + root->val);
//         string ans = smallest(s, t);
//         cout << s << " " << t << " " << ans << endl;
//         // ans += ('a' + root->val); // need to add this root value before comparing
//         return ans;
//     }
// };