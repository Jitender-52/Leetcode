class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));
        
        for(int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 1; j <= amount; j++)
            {
                 if(j >= coins[i])
                     dp[i][j] = dp[i+1][j] + dp[i][j-coins[i]]; // Good Condition need to take care of this condition
                else
                    dp[i][j] = dp[i+1][j];
            }
        }
        return dp[0][amount];
    }
};
    
    
    
//     Runtime: 29 ms, faster than 53.87% of C++ online submissions for Coin Change II.
// Memory Usage: 18.7 MB, less than 24.11% of C++ online submissions for Coin Change II.

    
//     int solve(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
//     {
//         int n = coins.size();
//         if(amount == 0)
//             return 1;
//         if(amount < 0 || i >= n)
//             return 0;
//         if(dp[i][amount] != -1)
//             return dp[i][amount];
//         return dp[i][amount] = solve(i+1, amount, coins, dp) + solve(i, amount - coins[i], coins, dp);
//     }
    
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
//         return solve(0, amount, coins, dp);
//     }
// };