class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 1));
        
        int ans = INT_MIN;
        for(int i = n-1; i >= 0; i--)
        {
            int a = dp[i+1][0] * nums[i];
            int b = dp[i+1][1] * nums[i];
            dp[i][0] = min(nums[i], min(a, b));
            dp[i][1] = max(nums[i], max(a, b));
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};