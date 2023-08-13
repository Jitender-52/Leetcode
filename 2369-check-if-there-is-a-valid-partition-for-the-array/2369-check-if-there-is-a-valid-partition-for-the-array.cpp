class Solution {
public:
    
    bool valid(int i, vector<int> &nums, vector<int> &dp)
    {
        int n = nums.size();
        if(i >= n)
            return true;
        if(dp[i] != -1)
            return dp[i];
        bool check = false;
        if(i + 2 < n)
        {
            if(nums[i] == nums[i+1] && nums[i+1] == nums[i+2] && valid(i+3, nums, dp))
                return dp[i] = true;
            if(nums[i] + 1 == nums[i+1] && nums[i+1] + 1 == nums[i+2] && valid(i+3, nums, dp))
                return dp[i] = true;
        }
        if(i + 1 < n && nums[i] == nums[i+1] && valid(i+2, nums, dp))
            return dp[i] = true;
        return dp[i] = false;
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return valid(0, nums, dp);
    } 
};