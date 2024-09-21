class Solution {
public:
    
//     Runtime: 14 ms, faster than 58.57% of C++ online submissions for Lexicographical Numbers.
// Memory Usage: 13.8 MB, less than 69.49% of C++ online submissions for Lexicographical Numbers.
    
    void dfs(int x, int n, vector<int> &ans)
    {
        if(x == 0)
        {
            for(int i = 1; i <= 9; i++)
                dfs(i, n, ans);
        }
        if(x > 0 && x <= n)
        {
            ans.push_back(x);
            for(int i = 0; i <= 9; i++)
            {
                int a = x * 10 + i;
                dfs(a, n, ans);
            }
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        dfs(0, n, ans);
        return ans;
    }
};
    
    
//     Runtime: 104 ms, faster than 14.96% of C++ online submissions for Lexicographical Numbers.
// Memory Usage: 20.3 MB, less than 32.39% of C++ online submissions for Lexicographical Numbers.
    
//     vector<int> lexicalOrder(int n) {
//         vector<string> ans;
//         vector<int> v;
//         for(int i = 0; i < n; i++)
//         {
//             ans.push_back(to_string(i + 1));
//         }
//         sort(ans.begin(), ans.end());
//         for(int i = 0; i < n; i++)
//         {
//             v.push_back(stoi(ans[i]));
//         }
//         return v;
//     }
// };
    
    
