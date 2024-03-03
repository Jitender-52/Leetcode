
// Solving by understanding trie from discussion part

class TrieNode{
  public:
    unordered_map<int, TrieNode*> child;
};

TrieNode* insert(TrieNode *root, string &s)
{
    TrieNode *curr = new TrieNode();
    curr = root;
    for(auto i : s)
    {
        if(curr->child[i] == NULL)  // curr->child is a map
        {
            curr->child[i] = new TrieNode();
        }
        curr = curr->child[i];
    }
    return root;
}

class Solution {
public:
    
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode *root = new TrieNode();
        for(auto i : arr1)
        {
            string s = to_string(i);
            root = insert(root, s);
        }
        
        int ans = 0;
        for(auto j : arr2)
        {
            string s = to_string(j);
            TrieNode *curr = root;
            int count = 0;
            for(auto i : s)
            {
                if(curr->child[i] == NULL)
                    break;
                curr = curr->child[i];
                count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
    
//     Runtime: 1290 ms, faster than 10.28% of C++ online submissions for Find the Length of the Longest Common Prefix.
// Memory Usage: 155.5 MB, less than 62.00% of C++ online submissions for Find the Length of the Longest Common Prefix.
    
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         set<string> st;
//         for(auto i : arr1)
//         {
//             string s = to_string(i);
//             string x = "";
//             for(auto j : s)
//             {
//                 x += j;
//                 st.insert(x);
//             }
//         }
//         int ans = 0;
//         for(auto i : arr2)
//         {
//             string s = to_string(i);
//             string x = "";
//             for(auto j : s)
//             {
//                 x += j;
//                 if(st.find(x) != st.end())
//                     ans = max(ans, (int)x.length());
//             }
//         }
//         return ans;
//     }
// };
    
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         int ans = 0;
//         for(auto x : arr1)
//         {
//             for(auto y : arr2)
//             {
//                 int count = 0;
//                 string s = to_string(x), t = to_string(y);
//                 for(int i = 0; i < s.length(), i < t.length(); i++)
//                 {
//                     if(s[i] != t[i])
//                         break;
//                     count++;
//                 }
//                 ans = max(ans, count);
//             }
//         }
//         return ans;
//     }
// };