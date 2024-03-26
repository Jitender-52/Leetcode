class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // vector<int> dist(n*n, n*n);
        
        auto isValid = [&](int i, int j)
        {
            return i >= 0 && i < n && j >= 0 && j  < n;  
        };
        
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        
        vector<vector<int>> dist = grid;
        vector<vector<int>> vis(n, vector<int> (n, 0));
        queue<pair<int,int>> q;
        q.push({0, 0});
        dist[0][0] = grid[0][0];
        vis[0][0] = 1;
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(isValid(nx, ny))
                {
                    // int d = max(grid[nx][ny], min(dist[nx][ny], dist[x][y]));
                    int d = max(grid[nx][ny], dist[x][y]);
                    if(!vis[nx][ny])
                    {
                        // d = max(grid[nx][ny], dist[x][y]);
                        vis[nx][ny] = 1;
                        dist[nx][ny] = d;
                        q.push({nx, ny});
                    }
                    else if(dist[nx][ny] > d)
                    {
                        dist[nx][ny] = d;
                        q.push({nx, ny});
                    }
                    // dist[nx][ny] = max(grid[nx][ny], min(dist[nx][ny], dist[x][y]));
                    // q.push({nx, ny});
                }
            }
        }
        return dist[n-1][n-1];
    }
};