class Solution {
public:
    
    bool match(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        int n = s.length();
        int m = p.length();
        
        if(i == n && j == m)
            return true;
        
        if(j >= m)
            return false;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        
        if(i == n)
        {
            for(j; j < m; j++)
            {
                if(p[j] != '*')
                    return dp[i][j] = 0;
            }
            ans = 1;
            return dp[i][j] = ans;
        }
        
        // cout << i << " " << j << endl;
        
        if(p[j] == '?' || s[i] == p[j])
        {
            if(match(i+1, j+1, s, p, dp))
                ans = 1;
                // return true;
        }
        else if(p[j] == '*')
        {
            for(int k = 0; i + k <= n; k++)
            {
                if(match(i+k, j+1, s, p, dp))
                {
                    ans = 1;
                    break;
                    // return true;
                }
            }
        }
        else
            ans = 0;
        return dp[i][j] = ans;
        // return false;
    }
    
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return match(0, 0, s, p, dp);
    }
};
    
    
    
//     bool match(int i, int j, string &s, string &p)
//     {
//         int n = s.length();
//         int m = p.length();
        
//         if(i == n && j == m)
//             return true;
        
//         if(j >= m)
//             return false;
        
//         if(i == n)
//         {
//             for(j; j < m; j++)
//             {
//                 if(p[j] != '*')
//                     return false;
//             }
//             return true;
//         }
        
//         // cout << i << " " << j << endl;
        
//         if(p[j] == '?' || s[i] == p[j])
//         {
//             if(match(i+1, j+1, s, p))
//                 return true;
//         }
//         else if(p[j] == '*')
//         {
//             for(int k = 0; i + k <= n; k++)
//             {
//                 if(match(i+k, j+1, s, p))
//                     return true;
//             }
//         }
//         return false;
//     }
    
//     bool isMatch(string s, string p) {
//         int n = s.length();
//         int m = p.length();
//         return match(0, 0, s, p);
//     }
// };