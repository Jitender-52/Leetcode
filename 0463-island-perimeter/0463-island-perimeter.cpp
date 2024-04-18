class Solution {
public:
    
//     Runtime: 96 ms, faster than 13.20% of C++ online submissions for Island Perimeter.
// Memory Usage: 101.1 MB, less than 32.36% of C++ online submissions for Island Perimeter.
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        int ans = 0;
        
        auto isValid = [&](int x, int y)
        {
            return x >= 0 && x < n && y >= 0 && y < m;  
        };
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(!isValid(x, y) || grid[x][y] == 0)
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};