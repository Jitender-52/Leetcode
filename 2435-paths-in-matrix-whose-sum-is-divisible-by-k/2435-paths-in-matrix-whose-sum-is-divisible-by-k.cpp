class Solution {
public:
    
    const int mod = 1e9+7;
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (k, 0)));
        
        dp[n-1][m-1][grid[n-1][m-1] % k] = 1;
        int count = grid[n-1][m-1];
        for(int i = n-2; i >= 0; i--)
        {
            // dp[i][m-1][l] = dp[i+1][m-1][l];
            (count += grid[i][m-1]) %= k;
            dp[i][m-1][count] = 1;
        }
        
        count = grid[n-1][m-1];
        for(int i = m-2; i >= 0; i--)
        {
            // dp[n-1][i][l] = dp[i+1][m-1][l];
            (count += grid[n-1][i]) %= k;
            dp[n-1][i][count] = 1;
        }
        
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = m-2; j >= 0; j--)
            {
                for(int l = 0; l < k; l++)
                {
                    int a = l + grid[i][j];
                    a %= k;
                    dp[i][j][a] = (0LL + dp[i+1][j][l] + dp[i][j+1][l]) % mod; 
                }
                // for(int l = 0; l < k; l++)
                // {
                //     dp[i][j][l] = dp[i+1][j][l] + dp[i][j+1][l];
                // }
            }
        }
        
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < m; j++)
        //     {
        //         // cout << i << " " << j << endl;
        //         for(int l = 0; l < k; l++)
        //         {
        //             cout << dp[i][j][l] << " ";
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
        
        return dp[0][0][0];
        
    }
};