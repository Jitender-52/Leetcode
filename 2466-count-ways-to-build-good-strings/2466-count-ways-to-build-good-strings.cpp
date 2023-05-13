class Solution {
public:
    
    const int mod = 1e9+7;
    
    long long good(int low, int high, int zero, int one, int l, vector<long long> &dp)
    {
        long long ans = 0;
        if(l >= low && l <= high)
        {
            ans++;
        }
        
        if(l > high)
            return 0;
        
        if(dp[l] != -1)
            return dp[l] % mod;
        
        ans += good(low, high, zero, one, l + one, dp) % mod;
        ans += good(low, high, zero, one, l + zero, dp) % mod;
        return dp[l] = ans % mod;        
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high+2, -1);
        return( good(low, high, zero, one, 0, dp) % mod);
    }
};