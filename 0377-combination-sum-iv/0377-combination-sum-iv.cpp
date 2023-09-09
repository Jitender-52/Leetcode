class Solution {
public:
    
    vector<int> v;
    
    int combination(int target, vector<int> &nums, vector<int> &dp)
    {
        int n = nums.size();
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        if(dp[target] != -1)
            return dp[target];
        dp[target] = 0;
        for(int i = 0; i < n; i++)
        {
            dp[target] += combination(target-nums[i], nums, dp);
        }
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, -1);
        return combination(target, nums, dp);
    }
};