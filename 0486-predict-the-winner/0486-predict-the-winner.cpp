class Solution {
public:
    
    int diff(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if(i == j)
            return nums[i];
        return max(nums[i] - diff(i+1, j, nums, dp), nums[j] - diff(i, j-1, nums, dp));
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return diff(0, n-1, nums, dp) >= 0;
    }
};