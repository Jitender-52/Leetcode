class Solution {
public:
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<uint> dp(1000+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if((i - nums[j]) >= 0)
                    dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};
    
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum IV.
// Memory Usage: 6.6 MB, less than 85.45% of C++ online submissions for Combination Sum IV.

    
    // vector<int> v;
    
//     int combination(int target, vector<int> &nums, vector<int> &dp)
//     {
//         int n = nums.size();
//         if(target == 0)
//             return 1;
//         if(target < 0)
//             return 0;
//         if(dp[target] != -1)
//             return dp[target];
//         dp[target] = 0;
//         for(int i = 0; i < n; i++)
//         {
//             dp[target] += combination(target-nums[i], nums, dp);
//         }
//         return dp[target];
//     }
    
//     int combinationSum4(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int> dp(target+1, -1);
//         return combination(target, nums, dp);
//     }
// };