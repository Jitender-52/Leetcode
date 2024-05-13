class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++)
        {
            if(grid[i][0] == 0)
            {
                for(int j = 0; j < m; j++)
                    grid[i][j] = 1 - grid[i][j];
            }
        }
        
        int ans = 0;
        for(int j = m-1; j >= 0; j--)
        {
            int one = 0, zero = 0;
            for(int i = 0; i < n; i++)
            {
                if(grid[i][j] == 0)
                    zero++;
                else
                    one++;
            }
            ans += (max(one, zero) << (m - 1 - j));
        }
        return ans;
    }
};