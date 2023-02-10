class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        
        vector<vector<int>> v(n, vector<int> (n, 1e6));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(grid[i][j] == 1)
                {
                    v[i][j] = 0;
                    continue;
                }
                if(i > 0)
                    v[i][j] = min(v[i][j], 1 + v[i-1][j]);
                if(j > 0)
                    v[i][j] = min(v[i][j], 1 + v[i][j-1]);
            }
        }
        
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0;j--)
            {
                if(grid[i][j] == 1)
                {
                    v[i][j] = 0;
                    continue;
                }
                if(i < n-1)
                    v[i][j] = min(v[i][j], 1 + v[i+1][j]);
                if(j < n-1)
                    v[i][j] = min(v[i][j], 1 + v[i][j+1]);
                if(v[i][j] >= 1e6)
                    continue;
                ans = max(ans, v[i][j]);
            }
        }
        
        if(ans == 0)
            return -1;
        
        return ans;
    }
};