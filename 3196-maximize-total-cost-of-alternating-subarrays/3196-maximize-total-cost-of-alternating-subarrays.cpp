class Solution {
public:
    
    long long dp[100001][2];
    
    long long solve(int i, int last, vector<int> &nums)
    {
        int n = nums.size();
        if(i >= n)
            return 0;
        if(dp[i][last] != -1)
            return dp[i][last];
        if(last == 0)  // means last was taken negative
            return dp[i][last] = 0LL + nums[i] + solve(i+1, 1, nums);
        
        return dp[i][last] = 0LL + max(nums[i] + solve(i+1, 1, nums), -1 * nums[i] + solve(i+1, 0, nums));
    }
    
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums);
    }
};