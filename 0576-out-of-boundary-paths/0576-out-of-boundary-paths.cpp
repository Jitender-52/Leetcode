class Solution {
public:
    
    const int mod = 1e9 + 7;
    int dp[51][51][51];
    int x, y, z;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
     
    int solve(int i, int j, int k)
    {
        if(i >= x || i < 0 || j >= y || j < 0)
            return 1;
        if(k == 0)
            return 0;
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        dp[i][j][k] = 0;
        for(int a = 0; a < 4; a++)
        {
            (dp[i][j][k] += solve(i + dx[a], j + dy[a], k-1)) %= mod;
        }
        return dp[i][j][k];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        x = m, y = n, z = maxMove;
        for(int i = 0; i < 51; i++)
        {
            for(int j = 0; j < 51; j++)
            {
                for(int k = 0; k < 51; k++)
                    dp[i][j][k] = -1;
            }
        }
        return solve(startRow, startColumn, maxMove);
    }
};