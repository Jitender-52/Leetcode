class Solution {
public:
    
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();   
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = dp[i-1][0] + (s1[i-1] - 0);
        }
        for(int j = 1; j <= m; j++)
        {
            dp[0][j] = dp[0][j-1] + (s2[j-1] - 0);
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    dp[i][j] = min((s1[i-1] - 0) + dp[i-1][j], (s2[j-1] - 0) + dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
    
    
    
    // MLE
    
//     int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp)
//     {
//         int n = s1.length(), m = s2.length();   
//         if(i >= n || j >= m)
//             return 0;
//         if(dp[i][j] != -1)
//             return dp[i][j];
//         if(s1[i] == s2[j])
//             return dp[i][j] = 2 * (s1[i] - 0) + solve(i+1, j+1, s1, s2, dp);
//         return dp[i][j] = max(solve(i+1, j, s1, s2, dp), solve(i, j+1, s1, s2, dp));
//     }
    
//     int minimumDeleteSum(string s1, string s2) {
//         int n = s1.length(), m = s2.length();   
//         vector<vector<int>> dp(n, vector<int> (m, -1));
//         int sum = 0;
//         for(auto i : s1)
//             sum += (i - 0);
//         for(auto i : s2)
//             sum += (i - 0);
//         return sum - solve(0, 0, s1, s2, dp);
//     }
// };