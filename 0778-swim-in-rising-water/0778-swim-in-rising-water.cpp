class Solution {
public:
    // vector<vector<int>> vis;
    int vis[51][51];
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    
    bool dfs(int i, int j, int maxi, vector<vector<int>> &grid)
    {
        int n = grid.size();
        if(i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || grid[i][j] > maxi)
            return 0;
        if(i == n-1 && j == n-1)
            return 1;
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++)
        {
            if(dfs(i+dx[k], j+dy[k], maxi, grid))
                return true;
        }
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = max({2*(n-1), grid[0][0], grid[n-1][n-1]}), high = n * n - 1;
        // vis.resize(n, vector<int> (n));
        while(low <= high)
        {
            int mid = (low + high) / 2;
            // vector<vector<int>> vis(n, vector<int> (n, 0));
            memset(vis, false, sizeof vis);
            if(dfs(0, 0, mid, grid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low; // Why its working on low not low - 1;
    }
};
    
    
//     Runtime: 7 ms, faster than 95.55% of C++ online submissions for Swim in Rising Water.
// Memory Usage: 12.1 MB, less than 93.59% of C++ online submissions for Swim in Rising Water.
    
//     int swimInWater(vector<vector<int>>& grid) {
//         int n = grid.size();
//         // vector<int> dist(n*n, n*n);
        
//         auto isValid = [&](int i, int j)
//         {
//             return i >= 0 && i < n && j >= 0 && j  < n;  
//         };
        
//         vector<int> dx = {1, -1, 0, 0};
//         vector<int> dy = {0, 0, 1, -1};
        
//         vector<vector<int>> dist = grid;
//         vector<vector<int>> vis(n, vector<int> (n, 0));
//         queue<pair<int,int>> q;
//         q.push({0, 0});
//         dist[0][0] = grid[0][0];
//         vis[0][0] = 1;
        
//         while(!q.empty())
//         {
//             auto it = q.front();
//             q.pop();
//             int x = it.first;
//             int y = it.second;
//             for(int i = 0; i < 4; i++)
//             {
//                 int nx = x + dx[i];
//                 int ny = y + dy[i];
//                 if(isValid(nx, ny))
//                 {
//                     // int d = max(grid[nx][ny], min(dist[nx][ny], dist[x][y]));
//                     int d = max(grid[nx][ny], dist[x][y]);
//                     if(!vis[nx][ny])
//                     {
//                         // d = max(grid[nx][ny], dist[x][y]);
//                         vis[nx][ny] = 1;
//                         dist[nx][ny] = d;
//                         q.push({nx, ny});
//                     }
//                     else if(dist[nx][ny] > d)
//                     {
//                         dist[nx][ny] = d;
//                         q.push({nx, ny});
//                     }
//                     // dist[nx][ny] = max(grid[nx][ny], min(dist[nx][ny], dist[x][y]));
//                     // q.push({nx, ny});
//                 }
//             }
//         }
//         return dist[n-1][n-1];
//     }
// };