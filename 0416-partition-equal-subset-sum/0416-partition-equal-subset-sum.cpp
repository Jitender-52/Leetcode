class Solution {
public:
    
    // Space Optimization
    
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums)
            sum += i;
        if(sum % 2)
            return false;
        
        sum /= 2;
        vector<int> prev(sum+1, 0);
        prev[sum] = 1;
        for(int i = n-1; i >= 0; i--)
        {
            vector<int> curr(sum+1, 0);
            for(int j = 0; j <= sum; j++)
            {
                curr[j] = prev[j];
                if(j + nums[i] <= sum)
                    curr[j] |= prev[j+nums[i]];
            }
            prev = curr;
        }
        return prev[0];
    }
};

    
    
    
//     Runtime: 419 ms, faster than 30.70% of C++ online submissions for Partition Equal Subset Sum.
// Memory Usage: 95.8 MB, less than 18.61% of C++ online submissions for Partition Equal Subset Sum.
    
    // Tabulation Method
    
//     bool canPartition(vector<int>& nums) 
//     {
//         int n = nums.size();
//         int sum = 0;
//         for(auto i : nums)
//             sum += i;
//         if(sum % 2)
//             return false;
        
//         sum /= 2;
//         vector<vector<int>> dp(n+1, vector<int> (sum+1, 0));
//         dp[n][sum] = 1;
//         for(int i = n-1; i >= 0; i--)
//         {
//             for(int j = 0; j <= sum; j++)
//             {
//                 dp[i][j] |= dp[i+1][j];
//                 if(nums[i] + j <= sum)
//                     dp[i][j] |= dp[i+1][j+nums[i]];
//             }
//         }
//         return dp[0][0];
//     }
// };

    
    
    
//     Runtime: 544 ms, faster than 16.55% of C++ online submissions for Partition Equal Subset Sum.
// Memory Usage: 236.1 MB, less than 5.13% of C++ online submissions for Partition Equal Subset Sum.
    
//     bool partition(int i, int sum, int sum2, vector<int> &nums, vector<vector<int>> &dp)
//     {
//         int n = nums.size();
//         if(i == n)
//         {
//             return sum == sum2;
//         }
//         if(i >= n)
//             return 0;
        
//         if(dp[i][sum] != -1)
//             return dp[i][sum];
        
//         bool ans = false;
//         ans = ans | partition(i+1, sum + nums[i], sum2, nums, dp);
//         ans = ans | partition(i+1, sum, sum2 + nums[i], nums, dp);
//         return dp[i][sum] = ans;
//     }
    
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         for(int i = 0; i < n; i++)
//             sum += nums[i];
//         vector<vector<int>> dp(n, vector<int> (sum+1, -1));
//         return partition(0, 0, 0, nums, dp);
//     }
// };