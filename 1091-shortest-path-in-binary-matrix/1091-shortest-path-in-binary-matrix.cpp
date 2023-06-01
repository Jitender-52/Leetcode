class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        auto isValid = [=](int i, int j)
        {
            return (i >= 0 && i < n && j >= 0 && j < n);
        };
        
        auto bfs = [=]()
        {
            vector<vector<int>> v(n, vector<int> (n, 1e5));
            queue<pair<int,int>> q;
            if(grid[0][0] == 0)
            {
                q.push({0, 0});
                v[0][0] = 1;
            }
            while(!q.empty())
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i = -1; i <= 1; i++)
                {
                    for(int j = -1; j <= 1; j++)
                    {
                        int nr = r + i;
                        int nc = c + j;
                        if(isValid(nr, nc) && grid[nr][nc] == 0 && v[r][c] + 1 < v[nr][nc])
                        {
                            q.push({nr, nc});
                            v[nr][nc] = v[r][c] + 1;
                        }
                    }
                }
            }
            return v[n-1][n-1];
        };
        
        int ans  = bfs();
        return ans >= 1e5 ? -1 : ans;
    }
};