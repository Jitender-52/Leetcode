class Solution {
public:
    
    int paint(int i, int t, int rem, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp)
    {
        int n = cost.size();
        
//         if(rem <= t)
//         {
//             return 0;
//         }
        if(t >= n)
            return 0;
        
        if(i >= n)
            return 1e9;
        
        if(dp[i][t] != -1)
            return dp[i][t];
        
        int ans = 1e9;
        
        ans = min(ans, paint(i+1, t, rem, cost, time, dp));
        ans = min(ans, cost[i] + paint(i+1, t + 1 + time[i], rem-1, cost, time, dp));
        return dp[i][t] = ans;
        
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return paint(0, 0, n, cost, time, dp);
    }
};