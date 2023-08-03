class Solution {
public:
    
    bool isValid(int i, int j, int n, int m)
    {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }
    
    int cherryRecursive(int r, int c1, int c2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        int n = grid.size(), m = grid[0].size();
        // if(i >= n || i < 0 || j >= m || j < 0)
        //     return 0;
        if (!isValid(r, c1, n, m) || !isValid(r, c2, n, m))
            return 0;

        if (r >= n)
            return 0;

        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        int ans = 0;
        if (c1 == c2)
        {
            ans += grid[r][c1];
        }
        else
        {
            ans += grid[r][c1] + grid[r][c2];
        }
        int count = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                count = max(count, cherryRecursive(r + 1, c1 + i, c2 + j, grid, dp));
            }
        }
        ans += count;
        return dp[r][c1][c2] = ans;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return cherryRecursive(0, 0, m - 1, grid, dp);
    }
};