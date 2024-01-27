class Solution {
public:
    
    const int mod = 1e9 + 7;
    int dp[1001][1001];
    int solve(int n, int k)
    {
        if(k == 0)
            return 1;
        if(n < 0 || k < 0)
            return 0;
        if(dp[n][k] != -1)
            return dp[n][k];
        long long ans = 0;
        for(int x = 0; x <= min(k, n-1); x++)
        {
            (ans += solve(n-1, k-x)) %= mod;
        }
        return dp[n][k] = ans;
    }
    
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k);
    }
};