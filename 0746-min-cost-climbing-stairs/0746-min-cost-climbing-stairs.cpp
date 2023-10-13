class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2, INT_MAX);
        dp[n] = 0;
        dp[n+1] = 0;
        for(int i = n-1; i >= 0; i--)
        {
            dp[i] = min({dp[i], dp[i+1] + cost[i], dp[i+2] + cost[i]});
        }
        return min(dp[0], dp[1]);
    }
};