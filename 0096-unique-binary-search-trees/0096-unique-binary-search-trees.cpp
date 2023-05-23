class Solution {
public:
    
    int Trees(int n, vector<int> &dp)
    {
        if(n == 1 || n == 0)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans += Trees(i-1, dp) * Trees(n-i, dp);
        }
        return dp[n] = ans;
    }
    
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        int ans = 0;
        return Trees(n, dp);
    }
};