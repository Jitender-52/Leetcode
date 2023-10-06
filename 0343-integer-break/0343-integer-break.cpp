class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        for(int i = 1; i < n; i++)
            dp[i] = i;
        // dp[1] = 1;
        // dp[2] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }
        // for(int i = 0; i <= n; i++)
        //     cout << dp[i] << " ";
        // cout << endl;
        return dp[n];
    }
};