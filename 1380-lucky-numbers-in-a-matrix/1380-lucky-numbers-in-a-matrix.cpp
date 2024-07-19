class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row(n), col(m);
        for(int i = 0; i < n; i++)
        {
            int mini = 1e9;
            for(int j = 0; j < m; j++)
                mini = min(mini, matrix[i][j]);
            row[i] = mini;
        }
        for(int j = 0; j < m; j++)
        {
            int maxi = 0;
            for(int i = 0; i < n; i++)
                maxi = max(maxi, matrix[i][j]);
            col[j] = maxi;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == row[i] && matrix[i][j] == col[j])
                    ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};