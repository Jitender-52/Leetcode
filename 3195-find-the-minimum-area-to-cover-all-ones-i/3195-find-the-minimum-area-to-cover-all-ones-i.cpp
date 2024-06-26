class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mini1 = 1e3, mini2 = 1e3, maxi1 = 0, maxi2 = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j])
                {
                    mini1 = min(mini1, i);
                    maxi1 = max(maxi1, i);
                    mini2 = min(mini2, j);
                    maxi2 = max(maxi2, j);
                }
            }
        }
        return max(0, (maxi1 - mini1 + 1) * (maxi2 - mini2 + 1));
    }
};