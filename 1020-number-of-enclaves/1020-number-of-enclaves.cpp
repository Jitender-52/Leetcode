class Solution {
public:
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == 1)
                {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        
        auto isValid = [&](int i, int j)
        {
            return (i >= 0 && i < n && j >= 0 && j < m);  
        };
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(isValid(nx, ny) && grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans += grid[i][j];
            }
        }
        return ans;
    }
};
    
    
    
//     Runtime: 78 ms, faster than 63.53% of C++ online submissions for Number of Enclaves.
// Memory Usage: 26.5 MB, less than 93.74% of C++ online submissions for Number of Enclaves.
    
//     vector<pair<int,int>> dr = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

//     bool isValid(int x, int y, int n, int m)
//     {
//         return (x >= 0 && x < n && y >= 0 && y < m);
//     }

//     int numEnclaves(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         int ans = 0;
//         // vector<vector<int>> vis(n, vector<int> (m, 0));  // No need of visited
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {   
//                 if((i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == 1)
//                 {
//                     // cout << i << " " << j << endl;
//                     queue<pair<int,int>> q;
//                     q.push({i, j});
//                     grid[i][j] = 0;
//                     while(!q.empty())
//                     {
//                         auto it = q.front();
//                         q.pop();
//                         for(int k = 0; k < dr.size(); k++)
//                         {
//                             int x = it.first + dr[k].first;
//                             int y = it.second + dr[k].second; // doing first instead of second
//                             if(isValid(x, y, n, m) && grid[x][y] == 1)
//                             {
//                                 // cout << x << " " << y << endl;
//                                 q.push({x, y});
//                                 // vis[x][y] = 1;
//                                 grid[x][y] = 0;
//                             }
//                         }
//                     }
//                 }
//             }
//         }

//         // for(int i = 0; i < n; i++)
//         // {
//         //     for(int j = 0; j < m; j++)
//         //     {
//         //         if(grid[i][j] == 1 && !vis[i][j])
//         //         {
//         //             queue<pair<int,int>> q;
//         //             q.push({i, j});
//         //             vis[i][j] = 1;
//         //             int count = 0;
//         //             while(!q.empty())
//         //             {
//         //                 auto it = q.front();
//         //                 q.pop();
//         //                 ans++;
//         //                 for(int k = 0; k < dr.size(); k++)
//         //                 {
//         //                     int x = it.first + dr[k].first;
//         //                     int y = it.first + dr[k].second; // doing first instead of second
//         //                     if(isValid(x, y, n, m) && !vis[x][y] && grid[i][j] == 1)
//         //                     {
//         //                         q.push({x, y});
//         //                         vis[x][y] = 1;
//         //                     }
//         //                 }
//         //             }
//         //         }
//         //     }
//         // }
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 // cout << grid[i][j] << " ";
//                 ans += grid[i][j];
//             }
//             // cout << endl;
//         }
//         return ans;            
//     }
// };

    
    

    
//     int numEnclaves(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int ans = 0;
        
//         vector<vector<int>> vis(n, vector<int> (m, 0));
//         // vector<pair<int,int>> vis;
//         for(int i = 1; i < n-1; i++)
//         {
//             for(int j = 1; j < m-1; j++)
//             {
//                 if(grid[i][j] == 1)
//                 {
//                     queue<pair<int,int>> q;
//                     q.push({i,j});
//                     // vis[i][j] = 1;
//                     int count = 0;
//                     bool check = true;
//                     while(!q.empty())
//                     {
//                         auto temp = q.front();
//                         q.pop();
//                         for(int k = 0; k < dr.size(); k++)
//                         {
//                             int x = temp.first + dr[k].first;
//                             int y = temp.second + dr[k].second;
//                             if(isValid(x, y, n, m) && !vis[x][y])
//                             {
//                                 if(grid[x][y] == 1)
//                                 {
//                                     if(x == n || x == 0 || y == 0 || y == m)
//                                     {
//                                         count = 0;
//                                         check = false;
//                                         // break;
//                                     }
//                                     q.push({x, y});
//                                     vis[x][y] = 1;
//                                     count++;
//                                 }
//                             }
//                         }
//                     }
//                     if(!check)
//                         count = 0;
//                     ans += count;
//                 }
//             }
//         }
//         return ans;
//     }
// };