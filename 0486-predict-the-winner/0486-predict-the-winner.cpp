class Solution {
public:
    
//     Runtime: 137 ms, faster than 30.99% of C++ online submissions for Predict the Winner.
// Memory Usage: 7.7 MB, less than 29.30% of C++ online submissions for Predict the Winner.
    
    int diff(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if(i == j)
            return nums[i];
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = max(nums[i] - diff(i+1, j, nums, dp), nums[j] - diff(i, j-1, nums, dp));
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return diff(0, n-1, nums, dp) >= 0;
    }
};