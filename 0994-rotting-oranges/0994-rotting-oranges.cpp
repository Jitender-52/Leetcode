class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> v(n, vector<int> (m, 1e6));
        
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,1,-1};
        
        auto isValid = [&](int i, int j)
        {
            return (i >= 0 && i < n && j >= 0 && j < m);
        };
        
        auto bfs = [&](int i, int j)
        {
            queue<pair<int,int>> q;
            q.push({i, j});
            int count = 0;
            v[i][j] = count;
            
            while(!q.empty())
            {
                count++;
                int sz = q.size();
                for(int j = 0; j < sz; j++)
                {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    for(int i = 0; i < 4; i++)
                    {
                        int nr = r + dx[i];
                        int nc = c + dy[i];
                        if(isValid(nr, nc) && grid[nr][nc] == 1)
                        {
                            if(count < v[nr][nc])
                            {
                                v[nr][nc] = min(v[nr][nc], count);
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
            
        };
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                    bfs(i, j);
                else if(grid[i][j] == 0)
                    v[i][j] = 0;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans = max(ans, v[i][j]);
            }
        }
        return ans >= 1e6 ? -1 : ans;
    }
};