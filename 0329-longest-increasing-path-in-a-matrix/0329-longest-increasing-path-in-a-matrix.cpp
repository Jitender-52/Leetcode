class Solution {
public:
    
    int dfs(int i, int j, int last, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        // cout << "HII" << endl;
        int n = matrix.size(), m = matrix[0].size();
        if(i >= n || j >= m || i < 0 || j < 0)
            return 0;
        if(matrix[i][j] <= last)
        {
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        for(int k = 0; k < 4; k++)
        {
            // cout << "LOOP" << endl;
            dp[i][j] = max(dp[i][j], 1 + dfs(i + dx[k], j + dy[k], matrix[i][j], matrix, dp));
        }
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(dp[i][j] == -1)
                    dfs(i, j, -1, matrix, dp);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;        
    }
};