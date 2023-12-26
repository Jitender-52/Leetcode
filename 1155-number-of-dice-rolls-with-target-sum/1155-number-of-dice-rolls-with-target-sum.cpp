class Solution {
public:
  
    const int mod = 1e9 + 7;
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1, vector<long long> (target+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= target; j++)
            {
                for(int l = 1; l <= k; l++)
                {
                    if(j - l >= 0)
                        (dp[i][j] += dp[i-1][j - l]) %= mod;
                }
            }
        }
        return dp[n][target];
    }
};
    
//     Runtime: 23 ms, faster than 69.34% of C++ online submissions for Number of Dice Rolls With Target Sum.
// Memory Usage: 8.7 MB, less than 65.29% of C++ online submissions for Number of Dice Rolls With Target Sum.

    
//     const int mod = 1e9 + 7;
//     vector<vector<int>> dp;
    
//     int rolls(int n, int k, int target)
//     {
//         if(target < 0 || n < 0)
//             return 0;
//         if(target == 0 && n == 0)
//             return 1;
//         if(dp[n][target] != -1)
//             return dp[n][target];
//         long long ans = 0;
//         for(int i = 1; i <= k; i++)
//         {
//             (ans += rolls(n-1, k, target - i)) %= mod;
//         }
//         return dp[n][target] = ans;
//     }
    
//     int numRollsToTarget(int n, int k, int target) {
//         dp.resize(n+1, vector<int> (target+1, -1));
//         return rolls(n, k, target);
//     }
// };