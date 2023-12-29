class Solution {
public:
    
    vector<int> v;
    int t, n;
    int dp[301][11][1001];
    
    int solve(int i, int count, int maxi)
    {
        if(i == n && count == t)
            return maxi;
        if(i >= n || count > t)
            return 1e9;
        if(dp[i][count][maxi] != -1)
            return dp[i][count][maxi];
        int ans = 1e9;
        ans = min({ans, solve(i+1, count, max(maxi, v[i])), maxi + solve(i+1, count+1, v[i])});
        return dp[i][count][maxi] = ans;
    }
        
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        v = jobDifficulty;
        t = d;
        n = v.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= 10; j++)
            {
                for(int k = 0; k <= 1000; k++)
                    dp[i][j][k] = -1;
            }
        }
        int ans =  solve(0, 0, 0);
        return ans == 1e9 ? -1 : ans;
    }
};