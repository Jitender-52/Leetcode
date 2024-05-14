class Solution {
public:
    
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    
    int dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m)
            return 0;
        if(vis[i][j] || grid[i][j] == 0)
            return 0;
        int ans = 0;
        vis[i][j] = 1;
        for(int x = 0; x < 4; x++)
        {
            ans = max(ans, grid[i][j] + dfs(i+dx[x], j+dy[x], vis, grid));
        }
        vis[i][j] = 0;
        return ans;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans = max(ans, dfs(i, j, vis, grid));
            }
        }
        return ans;
    }
};