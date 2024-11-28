class Solution {
public:

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isValid(vector<vector<int>>& grid, int row, int col) 
    {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
    }
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));

        minObstacles[0][0] = grid[0][0];

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({minObstacles[0][0], 0, 0});
        while (!pq.empty()) 
        {
            vector<int> current = pq.top();
            pq.pop();
            int obstacles = current[0], row = current[1], col = current[2];
            if (row == m - 1 && col == n - 1) 
                return obstacles;

            for (vector<int>& dir : directions) 
            {
                int newRow = row + dir[0], newCol = col + dir[1];
                if (isValid(grid, newRow, newCol)) 
                {
                    int newObstacles = obstacles + grid[newRow][newCol];
                    if (newObstacles < minObstacles[newRow][newCol]) 
                    {
                        minObstacles[newRow][newCol] = newObstacles;
                        pq.push({newObstacles, newRow, newCol});
                    }
                }
            }
        }
        return minObstacles[m - 1][n - 1];
    }
};
    
//     int minimumObstacles(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> ans(n, vector<int> (m, 0));
//         ans[0][0] = grid[0][0];
//         for(int i = 1; i < n; i++)
//             ans[i][0] = ans[i-1][0] + grid[i][0];
//         for(int j = 1; j < m; j++)
//             ans[0][j] = ans[0][j-1] + grid[0][j];
//         for(int i = 1; i < n; i++)
//         {
//             for(int j = 1; j < m; j++)
//                 ans[i][j] = min(ans[i-1][j], ans[i][j-1]) + (grid[i][j] == 1);
//         }
//         return ans[n-1][m-1];
//     }
// };