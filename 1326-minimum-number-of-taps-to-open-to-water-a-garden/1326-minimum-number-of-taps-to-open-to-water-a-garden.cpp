class Solution {
public:
    
    int solve(int i, int last, vector<int> &ranges, vector<vector<int>> &dp)
    {
        int m = ranges.size();
        if(i >= m)
            return 0;
        int ans = 1e9;
        for(int j = i+1; j < m; j++)
        {
            if(ranges[j] == 0)
                continue;
            if(j - i <= ranges[j])
                ans = min(ans, 1 + solve(j+ranges[i], last, ranges, dp));
        }
        return ans;
    }
    
    int minTaps(int n, vector<int>& ranges) {
        int m = ranges.size();
        // vector<vector<int>> dp(m, vector<int> (101, -1));
        // return solve(0, 0, ranges, dp);
        
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for(int i = 0; i <= n; i++)
        {
            int start = max(0, i-ranges[i]);
            int end = min(n, i+ranges[i]);
            for(int j = start; j <= end; j++)
            {
                dp[end] = min(dp[end], 1+dp[j]);
            }
        }
        return dp[n] == 1e9 ? -1 : dp[n];
    }
};