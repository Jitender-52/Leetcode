class Solution {
public:
    
    double solve(int i, int j, unordered_map<int, unordered_map<int, double>> &dp)
    {
        if(i <= 0 && j <= 0)
            return 0.5;
        if(i <= 0)
            return 1;
        if(j <= 0)
            return 0;
        if(dp[i].count(j))
            return dp[i][j];
        double ans = 0;
        for(int k = 4; k > 0; k--)
        {
            ans += solve(i-k, j-(4-k), dp);
        }
        return dp[i][j] = ans/4.0;
    }
    
    double soupServings(int n) {
        int m = ceil(n / 25.0);
        unordered_map<int, unordered_map<int, double>> dp;
        
        for(int i = 0; i <= m; i++)
        {
            if(solve(i, i, dp) > 1 - 1e-5)
                return 1;
        }
        return solve(m, m, dp);
    }
};