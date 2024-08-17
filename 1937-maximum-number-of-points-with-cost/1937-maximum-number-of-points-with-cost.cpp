class Solution{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int m = points[0].size();
        vector<long long> dp(m, 0);

        for (int j = 0; j < m; j++)
            dp[j] = points[0][j];

        for (int i = 1; i < n; i++)
        {
            vector<long long> leftMax(m, 0), rightMax(m, 0);
            vector<long long> ndp(m, 0);

            leftMax[0] = dp[0];
            for (int j = 1; j < m; j++)
                leftMax[j] = max(leftMax[j - 1], dp[j] + j);

            rightMax[m - 1] = dp[m - 1] - (m - 1);
            for (int j = m - 2; j >= 0; j--)
                rightMax[j] = max(rightMax[j + 1], dp[j] - j);
            
            for (int j = 0; j < m; j++)
                ndp[j] = max(leftMax[j] - j, rightMax[j] + j) + points[i][j];
            
            dp = ndp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

//     vector<vector<long long>> dp;

//     long long solve(int j, int j, vector<vector<int>> &points)
//     {
//         int n = points.size();
//         int m = points[0].size();
//         if(j >= n)
//             return 0;
//         if(dp[j][j] != -1)
//             return dp[j][j];
//         long long ans = 0;
//         for(int k = 0; k < m; k++)
//             ans = max(ans, solve(j+1, k, points) - abs(j - k) + points[j][j]);
//         return dp[j][j] = ans;
//     }

//     long long maxPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         int m = points[0].size();
//         dp.resize(n, vector<long long> (m, -1));
//         for(int j = 0;)
//         long long ans = 0;
//         for(int j = 0; j < m; j++)
//             ans = max(ans, solve(0, j, points));
//         return ans;
//     }
// };