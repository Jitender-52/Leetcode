class Solution {
public:
    
    int dp[1001][3];
    
    int solve(int i, int j, vector<int> &rating)
    {
        int n = rating.size();
        if(j == 2)
            return 1;
        if(i >= n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        for(int k = i + 1; k < n; k++)
        {
            if(rating[k] > rating[i])
                ans += solve(k, j+1, rating);
        }
        return dp[i][j] = ans;
    }
        
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++)
            ans += solve(i, 0, rating);
        memset(dp, -1, sizeof(dp));
        reverse(rating.begin(), rating.end());
        for(int i = 0; i < n; i++)
            ans += solve(i, 0, rating);
        return ans;
    }
};