class Solution {
public:
    
    vector<int> drx = {0, 0, 1, -1};
    vector<int> dry = {1, -1, 0, 0};
    
    bool isValid(int x, int y, int n, int m)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    bool bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        
        bool check = true;
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            if(temp.first == 0 || temp.first == n-1 || temp.second == 0 || temp.second == m-1)
                check = false;
            for(int i = 0; i < 4; i++)
            {
                int x = temp.first + drx[i];
                int y = temp.second + dry[i];
                if(isValid(x, y, n, m)  && !vis[x][y] && grid[x][y] == 0)
                {
                    // if(x == 0 || x == n-1 || y == 0 || y == m-1)
                    //     check = false;
                    q.push({x, y});
                    vis[x][y] = 1;
                }
            }
        }    
        return check;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0 && !vis[i][j] && bfs(i, j, grid, vis))
                {
                    // cout << i << " " << j << endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};
    
    
    
//     Runtime: 23 ms, faster than 14.11% of C++ online submissions for Number of Closed Islands.
// Memory Usage: 14.5 MB, less than 8.05% of C++ online submissions for Number of Closed Islands.
    
    
//     int closedIsland(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<bool>> visit(m, vector<bool>(n));
//         int count = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 0 && !visit[i][j] && bfs(i, j, m, n, grid, visit)) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }

//     bool bfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
//         queue<pair<int, int>> q;
//         q.push({x, y});
//         visit[x][y] = 2;
//         bool isClosed = true;

//         vector<int> dirx{0, 1, 0, -1};
//         vector<int> diry{-1, 0, 1, 0};

//         while (!q.empty()) {
//             x = q.front().first;   // row nnumber
//             y = q.front().second;  // column number
//             q.pop();

//             for (int i = 0; i < 4; i++) {
//                 int r = x + dirx[i];
//                 int c = y + diry[i];
//                 if (r < 0 || r >= m || c < 0 || c >= n) {
//                     // (x, y) is a boundary cell.
//                     isClosed = false;
//                 } else if (grid[r][c] == 0 && !visit[r][c]) {
//                     q.push({r, c});
//                     visit[r][c] = true;
//                 }
//             }
//         }

//         return isClosed;
//     }
// };