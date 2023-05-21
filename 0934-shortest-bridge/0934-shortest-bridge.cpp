class Solution {
public:
    
    
    int dir[5] = {0, 1, 0, -1, 0};
    
    void paint(vector<vector<int>>& A, int i, int j, vector<pair<int, int>> &q) {
        if (min(i, j) >= 0 && max(i, j) < A.size() && A[i][j] == 1) {
            A[i][j] = 2;
            q.push_back({i, j});
            for (int d = 0; d < 4; ++d)
                paint(A, i + dir[d], j + dir[d + 1], q);
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        vector<pair<int, int>> q;
        for (int i = 0; q.size() == 0 && i < A.size(); ++i)
            for (int j = 0; q.size() == 0 && j < A[0].size(); ++j)
                paint(A, i, j, q);
        while (!q.empty()) {
            vector<pair<int, int>> q1;
            for (auto [i, j] : q) {
                for (int d = 0; d < 4; ++d) {
                    int x = i + dir[d], y = j + dir[d + 1];
                    if (min(x, y) >= 0 && max(x, y) < A.size()) {
                        if (A[x][y] == 1)
                            return A[i][j] - 2;
                        if (A[x][y] == 0) {
                            A[x][y] = A[i][j] + 1;
                            q1.push_back({x, y});
                        }
                    }
                }
            }
            swap(q, q1);
        }
        return 0;
    } 
};
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