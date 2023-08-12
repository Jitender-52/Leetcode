class Solution {
public:
    
    
    int longest(int i, int j, vector<int> &v, vector<vector<int>> &dp)
    {
        int n = v.size();
        if(i >= n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(v[i] > v[j])
            dp[i][j] = max(dp[i][j], 1 + longest(i+1, i, v, dp));
        dp[i][j] = max(dp[i][j], longest(i+1, j, v, dp));
        return dp[i][j];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        vector<int> v(n+1);
        v[0] = -1e4;
        for(int i = 0; i < n; i++)
            v[i+1] = nums[i];
        return longest(1, 0, v, dp); 
    }
};