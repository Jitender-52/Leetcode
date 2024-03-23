class Solution {
public:
    
    const int mod = 1e9 + 7;
    int solve(int i, int last, int count, int n, vector<int> &rollMax, vector<vector<vector<int>>> &dp)
    {
        if(last > 0 && count > rollMax[last-1])
            return 0;
        if(i > n)
            return 1;
        if(dp[i][last][count] != -1)
            return dp[i][last][count];
        int ans = 0;
        for(int j = 1; j <= 6; j++)
        {
            if(j == last)
            {
                (ans += solve(i+1, j, count+1, n, rollMax, dp)) %= mod;
            }
            else
                (ans += solve(i+1, j, 1, n, rollMax, dp)) %= mod;
        }
        return dp[i][last][count] = ans;
    }
    
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (7, vector<int> (16, -1)));
        return solve(1, 0, 0, n, rollMax, dp);
    }
};