class Solution {
public:
    
    int dp[101][101];
    
    int solve(int i, int j, string ring, string key)
    {
        int n = ring.length();
        int m = key.length();
        if(j >= m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 1e9;
        for(int k = 0; k < n; k++)
        {
            if(ring[k] == key[j])
                ans = min(ans, 1 + min(min(i + n - k, k + n - i), abs(k - i)) + solve(k, j+1, ring, key));  // to understand inside min condition check tc 25(i.e. if k < i then inside min second condition will work)
        }
        return dp[i][j] = ans;
    }
    
    int findRotateSteps(string ring, string key) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, ring, key);
    }
};