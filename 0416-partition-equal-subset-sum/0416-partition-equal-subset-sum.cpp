class Solution {
public:
    
    bool partition(int i, int sum, int sum2, vector<int> &nums, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if(i == n)
        {
            return sum == sum2;
        }
        if(i >= n)
            return 0;
        
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        bool ans = false;
        ans = ans | partition(i+1, sum + nums[i], sum2, nums, dp);
        ans = ans | partition(i+1, sum, sum2 + nums[i], nums, dp);
        return dp[i][sum] = ans;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += nums[i];
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return partition(0, 0, 0, nums, dp);
    }
};