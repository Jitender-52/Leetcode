class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int a = INT_MAX;
                if(j > 0)
                    a = min(a, matrix[i-1][j-1]);
                a = min(a, matrix[i-1][j]);
                if(j < n-1)
                    a = min(a, matrix[i-1][j+1]);
                matrix[i][j] += a;
            }
        }
        int ans = INT_MAX;
        for(int j = 0; j < m; j++)
            ans = min(ans, matrix[n-1][j]);
        return ans;
    }
};
    
    
//     int minimum(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
//     {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         if(i < 0 || j < 0 || i > n || j >= m)
//             return 1e6;
//         if(i == n)
//             return 0;
//         if(dp[i][j] != -1)
//             return dp[i][j];
//         int ans = matrix[i][j];
//         ans += min(minimum(i+1, j-1, matrix, dp), min(minimum(i+1, j, matrix, dp), minimum(i+1, j+1, matrix, dp)));
//         return dp[i][j] = ans;
//     }
    
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int ans = INT_MAX;
//         vector<vector<int>> dp(m, vector<int> (n, -1));
//         for(int j = 0; j < n; j++)
//         {
//             ans = min(ans, minimum(0, j, matrix, dp));
//         }
//         return ans;
//     }
// };