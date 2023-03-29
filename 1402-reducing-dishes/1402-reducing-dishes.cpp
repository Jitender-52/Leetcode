class Solution {
public:
    
    int satisfy(int i, int count, vector<int> &satisfaction, vector<vector<int>> &dp)
    {
        int n = satisfaction.size();
        if(i >= n)
            return 0;
        if(dp[i][count] != -1)
            return dp[i][count];
        return dp[i][count] = max(count * satisfaction[i] + satisfy(i+1, count+1, satisfaction, dp), satisfy(i+1, count, satisfaction, dp));
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return satisfy(0, 1, satisfaction, dp);
    }
};