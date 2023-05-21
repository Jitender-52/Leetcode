class Solution {
public:
    
//     Runtime: 57 ms, faster than 51.79% of C++ online submissions for Shortest Bridge.
// Memory Usage: 18.8 MB, less than 88.20% of C++ online submissions for Shortest Bridge.
    
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    
        int shortestBridge(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            
            queue<pair<int,int>> q1, q;
            
            // auto isValid = [=](int i, int j)
            auto isValid = [&](int i, int j)
            {
              return (i >= 0 && i < n && j >= 0 && j < m);  
            };
            
            auto bfs = [&](int i, int j)
            {
                q1.push({i, j});
                q.push({i, j});
                grid[i][j] = -1;
                while(!q1.empty())
                {
                    auto p = q1.front();
                    q1.pop();
                    for(int i = 0; i < 4; i++)
                    {
                        int x = p.first + dx[i];
                        int y = p.second + dy[i];
                        if(isValid(x, y) && grid[x][y] == 1)
                        {
                            q1.push({x, y});
                            q.push({x, y});
                            grid[x][y] = -1;
                        }
                    }
                }
            };
            
            bool check = false;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(grid[i][j] == 1)
                    {
                        bfs(i, j);
                        check = true;
                        break;
                    }
                }
                if(check)
                    break;
            }
            
            int ans = 0;
            while(!q.empty())
            {
                int s = q.size();
                for(int i = 0; i < s; i++)
                {
                    auto p = q.front();
                    q.pop();
                    for(int j = 0; j < 4; j++)
                    {
                        int x = p.first + dx[j];
                        int y = p.second + dy[j];
                        // cout << x << " " << y << endl;
                        if(isValid(x, y))
                        {
                            if(grid[x][y] == 1)
                                return ans;
                            else if(grid[x][y] == 0)
                            {
                                q.push({x, y});
                                grid[x][y] = -1;
                            }
                        }
                    }
                }
                ans++;
            }
            return ans;
        }
};
    
    
//     Runtime: 43 ms, faster than 92.16% of C++ online submissions for Shortest Bridge.
// Memory Usage: 22.2 MB, less than 35.09% of C++ online submissions for Shortest Bridge.
    
//     int dir[5] = {0, 1, 0, -1, 0};
    
//     void paint(vector<vector<int>>& A, int i, int j, vector<pair<int, int>> &q) {
//         if (min(i, j) >= 0 && max(i, j) < A.size() && A[i][j] == 1) {
//             A[i][j] = 2;
//             q.push_back({i, j});
//             for (int d = 0; d < 4; ++d)
//                 paint(A, i + dir[d], j + dir[d + 1], q);
//         }
//     }
//     int shortestBridge(vector<vector<int>>& A) {
//         vector<pair<int, int>> q;
//         for (int i = 0; q.size() == 0 && i < A.size(); ++i)
//             for (int j = 0; q.size() == 0 && j < A[0].size(); ++j)
//                 paint(A, i, j, q);
//         while (!q.empty()) {
//             vector<pair<int, int>> q1;
//             for (auto [i, j] : q) {
//                 for (int d = 0; d < 4; ++d) {
//                     int x = i + dir[d], y = j + dir[d + 1];
//                     if (min(x, y) >= 0 && max(x, y) < A.size()) {
//                         if (A[x][y] == 1)
//                             return A[i][j] - 2;
//                         if (A[x][y] == 0) {
//                             A[x][y] = A[i][j] + 1;
//                             q1.push_back({x, y});
//                         }
//                     }
//                 }
//             }
//             swap(q, q1);
//         }
//         return 0;
//     } 
// };
    // int shortestBridge(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> ud(n, vector<int> (m, 1e5));
//         vector<vector<int>> lr(n, vector<int> (m, 1e5));
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 if(grid[i][j] == 1)
//                 {
//                     ud[i][j] = 0;
//                     lr[i][j] = 0;
//                 }
//             }
//         }
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 if(i > 0)
//                 {
//                     ud[i][j] = min(ud[i][j], ud[i-1][j] + 1);
//                 }
//                 if(j > 0)
//                 {
//                     lr[i][j] = min(lr[i][j], lr[i][j-1] + 1);
//                 }
//             }
//         }
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 if(i < n-1)
//                 {
//                     ud[i][j] = min(ud[i][j], ud[i+1][j] + 1);
//                 }
//                 if(j < m-1)
//                 {
//                     lr[i][j] = min(lr[i][j], lr[i][j+1] + 1);
//                 }
//             }
//         }
        
//         int ans = m + n;
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 if(grid[i][j] != 1)
//                 {
//                     ans = min(ans, ud[i][j] + lr[i][j] - 1);
//                 }
//             }
//         }
        
//         // for(int i = 0; i < n; i++)
//         // {
//         //     for(int j = 0; j < m; j++)
//         //     {
//         //         cout << ud[i][j] << "-"<< lr[i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }
        
//         return ans;
//     }
// };