class Solution {
public:
    
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    
    bool isPath(vector<vector<int>> grid)
    {
        int n = grid.size();
        
        auto isValid = [&](int x, int y)
        {
            return (x >= 0 && x < n && y >= 0 && y < n);
        };
        
        queue<pair<int,int>> q;
        if(grid[0][0] == 0)
        {
            q.push({0, 0});
        }
        
        while(!q.empty())
        {        
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto it = q.front();
                q.pop();
                auto a = it.first;
                auto b = it.second;
                
                if(a == n-1 && b == n-1)
                    return true;
                
                for(int j = 0; j < 4; j++)
                {
                    int x = a + dx[j];
                    int y = b + dy[j];
                    if(isValid(x, y) && grid[x][y] == 0)
                    {
                        q.push({x, y});
                        grid[x][y] = 1;
                    }
                }
            }
        }
        return false;        
    }
    
    bool isFeasible(vector<vector<int>> grid, int mid)
    {
        int n = grid.size();
        queue<pair<int,int>> q;
        // map<pair<int,int>, int> vis;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    // vis[{i, j}] = 1;
                    grid[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        
        auto isValid = [&](int x, int y)
        {
            return (x >= 0 && x < n && y >= 0 && y < n);
        };
        
        int k = mid;
        while(!q.empty() && k--)
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto it = q.front();
                q.pop();
                auto a = it.first;
                auto b = it.second;
                // if(grid[a][b] == 1)
                // {
                //     continue;
                // }
                // cout << a << " " << b << endl;
                // grid[a][b] = 1;
                // vis[{a, b}] = 1;
                for(int j = 0; j < 4; j++)
                {
                    int x = a + dx[j];
                    int y = b + dy[j];
                    if(isValid(x, y) && grid[x][y] == 0)
                    {
                        grid[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }   
        }
        // cout << mid << endl;
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if(isPath(grid))
        {
            // cout << "YES" << endl;
            return true;
        }
        cout << "NO" << endl;
        return false;
        
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int l = 0, r = 2 *n;
        
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(isFeasible(grid, mid))
                l = mid + 1;
            else
                r = mid - 1;
        }
        // cout << endl << endl;
        return l;
        
//         vector<pair<int,int>> v;
//         v.push_back({0, 0});
//         v.push_back({n-1, n-1});
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(grid[i][j] == 1)
//                     v.push_back({i, j});
//             }
//         }
        
//         int ans = 0;
//         for(int i = 0; i < v.size(); i++)
//         {
//             for(int j = i+1; j < v.size(); j++)
//             {
//                 ans = max(ans, (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second)) / 2 - 1);
//                 ans = max(ans, )
//             }
//         }
//         return ans;
    }
};