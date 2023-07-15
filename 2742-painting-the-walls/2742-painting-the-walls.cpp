class Solution {
public:
    
    int paint(int i, int t, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp)
    {
        int n = cost.size();
        
        if(t >= n)
            return 0;
        
        if(i >= n)
            return 1e9;
        
        if(dp[i][t] != -1)
            return dp[i][t];
        
        int ans = 1e9;
        
        ans = min(ans, paint(i+1, t, cost, time, dp));
        ans = min(ans, cost[i] + paint(i+1, t + time[i] + 1, cost, time, dp));
        // 1 is added for the time of the free painter and if this time is equal to or greater than n then it means that all the n walls are painted (as in the busy time of main painter the free painter will paint the time[i] walls and 1 wall will be painted by the paid painter so total walls painted will be time[i] + 1);
        return dp[i][t] = ans;
        
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return paint(0, 0, cost, time, dp);
    }
};