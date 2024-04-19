class Solution {
public:
    
//     Runtime: 62 ms, faster than 40.98% of C++ online submissions for Number of Islands.
// Memory Usage: 12.6 MB, less than 39.11% of C++ online submissions for Number of Islands.
// Show off your acceptance:
    
    
//     Solve Using BFS Also

    
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis)
    {
        int m = grid.size();
        int n = grid[i].size();

        if(vis[i][j])
        {
            return;
        }

        vis[i][j] = true;

        // cout << i << " " << j << endl;

        if(i > 0 && grid[i-1][j] == '1')
            dfs(grid, i - 1, j, vis);
        if(i < m-1 && grid[i+1][j] == '1')
           dfs(grid, i + 1, j, vis);
        if(j > 0 && grid[i][j-1] == '1')
            dfs(grid, i, j-1, vis);
        if(j < n-1 && grid[i][j+1] == '1')
            dfs(grid, i, j+1, vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    // vis[i][j] = true;
                    dfs(grid, i, j, vis);
                    count++;
                }
            }
        }
        return count;
    }
};




// class Solution {
// public:
    
//     bool bfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis)
// {
//     int m = grid.size();
//     int n = grid[i].size();

//     if(vis[i][j])
//     {
//         return true;
//     }

//     if (i < 0 || j < 0 || i >= m || j >= n)
//     {
//         return true;
//     }
//     else if (grid[i][j] == '0')
//     {
//         return true;
//     }

//     vis[i][j] = true;

//     vis[i][j] = true;
//     bool left = bfs(grid, i + 1, j, vis);
//     bool right = bfs(grid, i - 1, j, vis);
//     bool top = bfs(grid, i, j - 1, vis);
//     bool bottom = bfs(grid, i, j + 1, vis);
//     if (left && right && top && bottom)
//     {
//         return true;
//     }
//     return false;
// }
    
//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size();
//     int n = grid[0].size();

//     vector<vector<bool>> vis(m, vector<bool>(n, false));
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (!vis[i][j] && grid[i][j] == '1')
//             {
//                 vis[i][j] = true;
//                 bool left = bfs(grid, i + 1, j, vis);
//                 bool right = bfs(grid, i - 1, j, vis);
//                 bool top = bfs(grid, i, j - 1, vis);
//                 bool bottom = bfs(grid, i, j + 1, vis);
//                 if (left && right && top && bottom)
//                 {
//                     count++;
//                 }
//             }
//         }
//     }
//     return count;
//     }
// };