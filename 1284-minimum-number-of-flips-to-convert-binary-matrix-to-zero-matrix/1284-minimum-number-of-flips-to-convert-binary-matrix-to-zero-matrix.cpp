class Solution {
public:
    
    int n, m;
    
    vector<int> dx = {1, -1, 0, 0, 0};
    vector<int> dy = {0, 0, 1, -1, 0};
    
    vector<vector<vector<int>>> v;
    
    bool isValid(int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    int dfs(vector<vector<int>> &mat, map<vector<vector<int>>, int> &mp)
    {          
        bool check = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 1)
                    check = false;
            }
        }
        
        if(check)
        {
            return 0;
        }
        
        if(mp[mat] != 0)
            return mp[mat];
        
        mp[mat] = 1e6;
        
        int ans = 1e6;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                vector<vector<int>> v = mat;
                for(int k = 0; k < 5; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(isValid(x, y))
                    {
                        v[x][y] ^= 1;
                    }
                }
                // mp[v] = min(ans, 1 + dfs(v, mp));
                int a = 1 + dfs(v, mp);
                ans = min(ans, a);
            }
        }
        return mp[mat] = ans;
    }
    
    int minFlips(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        map<vector<vector<int>>, int> mp;
        int ans = dfs(mat, mp);
        return ans >= 1e6 ? -1 : ans;
    }
};
    
    
//     int count = 0;
//     int dfs(vector<vector<int>> &mat, vector<vector<int>> &v, bool &start)
//     {
//         // cout << "HII" << endl;
//         int n = mat.size();
//         int m = mat[0].size();
//         bool check = true;
//         bool flag = true;
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 if(mat[i][j] == 1)
//                     check = false;
//                 if(mat[i][j] != v[i][j])
//                     flag = false;
//                 cout << mat[i][j] <<" ";
//             }
//             cout << endl;
//         }
//         if(check)
//             return 0;
//         if(flag && start)
//             return 1e6;
        
//         if(count == 100)
//             return 0;
//         count++;
        
//         start = true;
        
//         int ans = 1e6;
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(i > 0)
//                     mat[i-1][j] ^= 1;
//                 if(j > 0)
//                     mat[i][j-1] ^= 1;
//                 if(i < n-1)
//                     mat[i+1][j] ^= 1;
//                 if(j < m-1)
//                     mat[i][j+1] ^= 1;
//                 mat[i][j] ^= 1;
//                 ans = min(ans, 1 + dfs(mat, v, start));
//                 if(i > 0)
//                     mat[i-1][j] ^= 1;
//                 if(j > 0)
//                     mat[i][j-1] ^= 1;
//                 if(i < n-1)
//                     mat[i+1][j] ^= 1;
//                 if(j < m-1)
//                     mat[i][j+1] ^= 1;
//                 mat[i][j] ^= 1;
//             }
//         }
//         return ans;
//     }
    
//     int minFlips(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();
        
//         vector<vector<int>> v = mat;
        
//         bool start = false;
//         int ans = dfs(mat, v, start);
        
//         if(ans >= 1e6)
//             return -1;
//         return ans;
//     }
// };