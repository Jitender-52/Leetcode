class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        // for(int i = 0; i < n; i++)
        // {
        //     dp[i][m-1] = 1;
        // }
        
        for(int j = m-2; j >= 0; j--)
        {
            for(int i = 0; i < n; i++)
            {
                if(i == 0)
                {
                    if(grid[i][j] < grid[i][j+1])
                        dp[i][j] = max(dp[i][j], dp[i][j+1] + 1);
                    if(grid[i][j] < grid[i+1][j+1])
                        dp[i][j] = max(dp[i][j], dp[i+1][j+1] + 1);
                }
                else if(i == n-1)
                {
                    if(grid[i][j] < grid[i][j+1])
                        dp[i][j] = max(dp[i][j], dp[i][j+1] + 1);
                    if(grid[i][j] < grid[i-1][j+1])
                        dp[i][j] = max(dp[i][j], dp[i-1][j+1] + 1);
                }
                else
                {
                    if(grid[i][j] < grid[i][j+1])
                        dp[i][j] = max(dp[i][j], dp[i][j+1] + 1);
                    if(grid[i][j] < grid[i+1][j+1])
                        dp[i][j] = max(dp[i][j], dp[i+1][j+1] + 1);
                    if(grid[i][j] < grid[i-1][j+1])
                        dp[i][j] = max(dp[i][j], dp[i-1][j+1] + 1);
                }
            }
        }
        
        // for(int i = 0; i < n;i++)
        // {
        //     for(int j = 0; j < m;j++)
        //     {
        //         cout << dp[i][j] <<  " ";
        //     }
        //     cout << endl;
        // }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};