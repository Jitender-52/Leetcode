class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums)
            sum += i;
        sum -= target;
        if(sum % 2 == 1 || sum < 0)
            return 0;
        sum /= 2;
        
        vector<vector<int>> dp(n, vector<int> (sum + 1, 0));
        dp[0][0] = 1;
        if(nums[0] <= sum)
            dp[0][nums[0]] += 1;
        // cout << sum << endl;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j - nums[i] >= 0)
                {
                    dp[i][j] += dp[i-1][j - nums[i]];
                }
            }
        }
        // cout << endl;
        // for(auto v : dp)
        // {
        //     for(auto i : v)
        //         cout << i << " ";
        //     cout << endl;
        // }
        return dp[n-1][sum];
    }
};
    
    
    
//     Runtime: 13 ms, faster than 69.30% of C++ online submissions for Target Sum.
// Memory Usage: 12.5 MB, less than 40.46% of C++ online submissions for Target Sum.
    
//     int solve(int i, int sum, vector<int> &nums, vector<vector<int>> &dp)
//     {
//         int n = nums.size();
//         if(i == n)
//             return sum == 0 ? 1 : 0;
//         if(i >= n || sum < 0)
//             return 0;
//         if(dp[i][sum] != -1)
//             return dp[i][sum];
//         return dp[i][sum] = solve(i+1, sum - nums[i], nums, dp) + solve(i+1, sum, nums, dp);
//     }
    
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int sum = 0;
//         for(auto i : nums)
//             sum += i;
//         sum -= target;
//         if(sum % 2 == 1 || sum < 0)
//             return 0;
//         sum /= 2;
//         vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
//         return solve(0, sum, nums, dp);
//     }
// };
    
    
//     Runtime: 965 ms, faster than 24.54% of C++ online submissions for Target Sum.
// Memory Usage: 9.1 MB, less than 85.25% of C++ online submissions for Target Sum.
    
//     int memo(int ind, int target, vector<int> &arr) {
//       if (ind == 0) 
//       {
//         if(target == 0 && arr[0] == 0) 
//             return 2;
//         // if(target == 0) 
//         //     return 1;
//         if (arr[ind] + target == 0)
//             return 1;
//         if (arr[ind] - target == 0)
//             return 1;
//         return 0;
//       }
        
//       int  plus = memo(ind - 1, target - arr[ind], arr);
//       int neg = memo(ind - 1, (target + arr[ind]), arr);
//       return plus + neg;
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         return memo(n-1, target, nums);
//     }
// };
    
    
    
//     int findTargetSumWays(vector<int>& nums, int target) {
        
//     }
// };