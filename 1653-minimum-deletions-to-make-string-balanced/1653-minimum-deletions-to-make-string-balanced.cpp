class Solution {
public:
    
    int minimumDeletions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 0; j < 2; j++)
            {
                if(s[i] == 'b')
                {
                    if(j == 0)
                        dp[i][j] = dp[i+1][j];
                    else
                        dp[i][j] = min(1 + dp[i+1][j], dp[i+1][j-1]);
                }
                else
                {
                    if(j == 0)
                        dp[i][j] = min(n-i, 1 + dp[i+1][j]);
                    else
                        dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][1];
    }
};
    
//     Runtime: 722 ms, faster than 5.95% of C++ online submissions for Minimum Deletions to Make String Balanced.
// Memory Usage: 258.1 MB, less than 5.12% of C++ online submissions for Minimum Deletions to Make String Balanced.
    
//     vector<vector<int>> dp;
//     int minimum(int i, int j, string &s)
//     {
//         int n = s.length();
//         if(i >= n)
//             return 0;
//         if(dp[i][j] != -1)
//             return dp[i][j];
//         if(s[i] == 'b')
//         {
//             if(j == 0)
//                 return dp[i][j] = minimum(i+1, j, s);
//             else
//                 return dp[i][j] = min(1 + minimum(i+1, j, s), minimum(i+1, j-1, s));
//         }
//         else
//         {
//             if(j == 0)
//                 return dp[i][j] = min(n - i, 1 + minimum(i+1, j, s)); // mybad used n-i-1
//             else
//                 return dp[i][j] = minimum(i+1, j, s);
//         }
//         // return dp[i][j] = minimum(i+1, j, s);
//     }
    
//     int minimumDeletions(string s) {
//         int n = s.length();
//         dp.resize(n+1, vector<int> (2, -1));
//         return minimum(0, 1, s);
//     }
// };