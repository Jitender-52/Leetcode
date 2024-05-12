class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> v(n-2, vector<int>(n-2));
        
        for(int i = 0; i <  n - 2; i++)
        {
            for(int j = 0; j < n - 2; j++)
            {
                int mini = 0;
                for(int k = i; k < i + 3; k++)
                {
                    for(int l = j; l < j + 3; l++)
                        mini = max(mini, grid[k][l]);   
                }
                v[i][j] = mini;
            }
        }
        return v;
    }
};