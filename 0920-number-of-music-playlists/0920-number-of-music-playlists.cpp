class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    long long solve(int i, int j, int n, int k, vector<vector<long long>> &dp)
    {
        if(i == 0 && j == 0)
        {
            return 1LL;
        }
        if(i == 0 || j == 0)
        {
            return 0LL;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        dp[i][j] = (solve(i-1, j-1, n, k, dp) * (n - j + 1)) % mod;
        if(j > k)
        {
            dp[i][j] += (solve(i - 1, j, n, k, dp) * (j - k)) % mod;
            dp[i][j] %= mod;
        }
        return dp[i][j];
    }
        
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(goal + 1, vector<long long> (n+1, -1));
        return solve(goal, n, n, k, dp);
    }
};