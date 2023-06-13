class Solution {
public:
    
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        
        vector<vector<int>> ans(n, vector<int> (m, 1e5));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        
        auto isValid = [&](int i, int j)
        {
            return i >= 0 && i < n && j >= 0 && j < m;
        };
        
        // auto bfs = [&](int i, int j)
        auto bfs = [&]()
        {
            // q.push({i, j});
            // ans[i][j] = 0;
            while(!q.empty())
            {
                // int sz = q.size();
                // for(int i = 0; i < sz; i++)
                // {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int j = 0; j < 4; j++)
                    {
                        int nx = x + dx[j];
                        int ny = y + dy[j];
                        if(isValid(nx, ny) && ans[nx][ny] > ans[x][y] + 1)
                        {
                            ans[nx][ny] = ans[x][y] + 1;
                            q.push({nx, ny});
                        }
                    }
                // }
            }
        };
        
        bfs();
        
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < m; j++)
        //     {
        //         if(mat[i][j] == 0)
        //             bfs(i, j);
        //     }
        // }
        return ans;
    }
};