class Solution {
public:
    
    const int mod = 1e9 + 7;
    int dp[5001][3][3][3];
    
    int solve(int i, int k, int l, int m, int n)
    {
        if(i >= n)
            return 1;
        if(dp[i][k][l][m] != -1)
            return dp[i][k][l][m];
        int ans = 0;
        for(int x = 0; x <= 2; x++)
        {
            for(int y = 0; y <= 2; y++)
            {
                for(int z = 0; z <= 2; z++)
                {
                    if(i == 0)
                    {
                        if(x != y && y != z)
                            (ans += solve(i+1, x, y, z, n)) %= mod;
                    }
                    else
                    {
                        if(x != k && x != y && y != l && y != z && z != m)
                            (ans += solve(i+1, x, y, z, n)) %= mod;
                    }
                }
            }
        }
        return dp[i][k][l][m] = ans;
    }
    
    int numOfWays(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, 0, n);
    }
};