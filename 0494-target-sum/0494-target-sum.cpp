class Solution {
public:
    
    int solve(int i, int sum, vector<int> &nums, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if(i == n)
            return sum == 0 ? 1 : 0;
        if(i >= n || sum < 0)
            return 0;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        return dp[i][sum] = solve(i+1, sum - nums[i], nums, dp) + solve(i+1, sum, nums, dp);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums)
            sum += i;
        sum -= target;
        if(sum % 2 == 1 || sum < 0)
            return 0;
        sum /= 2;
        vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
        return solve(0, sum, nums, dp);
    }
};
    
    
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