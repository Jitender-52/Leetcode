class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 1e9, count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m/2; j++)
            {
                if(grid[i][j] != grid[i][m-1-j])
                    count++;
            }
        }
        ans = min(ans, count);
        count = 0;
        for(int j = 0; j < m; j++)
        {
            for(int i = 0; i < n/2; i++)
            {
                if(grid[i][j] != grid[n-1-i][j])
                    count++;
            }
        }
        ans = min(ans, count);
        return ans;
    }
};