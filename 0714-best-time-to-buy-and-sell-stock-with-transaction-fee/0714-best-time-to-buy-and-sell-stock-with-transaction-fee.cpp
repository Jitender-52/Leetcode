class Solution {
public:
    
     int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> free(n, 0), hold(n, 0);
        
        // In order to hold a stock on day 0, we have no other choice but to buy it for prices[0].
        hold[0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            free[i] = max(free[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], free[i - 1] - prices[i]);
        }
        
        return free[n - 1];
    }
};
    
    
//     int profit(int i, int p, vector<int> &prices, int fee, int change, vector<vector<int>> &dp)
//     {
//         int n = prices.size();
//         if(i >= n)
//             return 0;
//         if(dp[i][change] != -1)
//             return dp[i][change];
//         int ans = 0;
//         if(change == 0)
//         {
//             ans = max(profit(i+1, prices[i], prices, fee, 1, dp), profit(i+1, p, prices, fee, change, dp));
//         }
//         else if(prices[i] - p - fee > 0)
//         {
//             ans = max(profit(i + 1, p, prices, fee, 0, dp) + prices[i] - p - fee, profit(i+1, p, prices, fee, change, dp));
//         }
//         else
//         {
//             ans = profit(i+1, p, prices, fee, change, dp);
//         }
        
//         return dp[i][change] = ans;
//     }
    
    
//         int profit(int i, vector<int> &prices, int fee, int change, vector<vector<int>> &dp)
//         {
//             int n = prices.size();
//             if(i >= n)
//                 return 0;
            
//             if(change == 0)
//             {
                
//             }
//             else
//             {
                
//             }
//         }
    
//     int maxProfit(vector<int>& prices, int fee) {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int> (2, -1));
        
//         return profit(0, 0, prices, fee, 0, dp);
        
//     }
// };