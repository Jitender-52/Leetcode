class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int paths(int i, int j, int prev, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] <= prev)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = 1 + (paths(i+1, j, grid[i][j], grid, dp) + 0LL + paths(i-1, j, grid[i][j], grid, dp) + paths(i, j+1, grid[i][j], grid, dp) + paths(i, j-1, grid[i][j], grid, dp)) % mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                (ans += paths(i, j, -1, grid, dp)) %= mod;
            }
        }
        return ans;
    }
};