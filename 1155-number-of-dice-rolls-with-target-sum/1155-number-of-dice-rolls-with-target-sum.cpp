class Solution {
public:
    
    const int mod = 1e9 + 7;
    vector<vector<int>> dp;
    
    int rolls(int n, int k, int target)
    {
        if(target < 0 || n < 0)
            return 0;
        if(target == 0 && n == 0)
            return 1;
        if(dp[n][target] != -1)
            return dp[n][target];
        long long ans = 0;
        for(int i = 1; i <= k; i++)
        {
            (ans += rolls(n-1, k, target - i)) %= mod;
        }
        return dp[n][target] = ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1, vector<int> (target+1, -1));
        return rolls(n, k, target);
    }
};