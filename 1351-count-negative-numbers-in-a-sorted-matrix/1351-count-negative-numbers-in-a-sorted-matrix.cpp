class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i = n-1;
        int j = 0;
        int ans = 0;
        while(i >= 0 && j < m)
        {
            while(j < m && grid[i][j] >= 0)
                j++;
            ans += m - j;
            i--;
        }
        return ans;
    }
};