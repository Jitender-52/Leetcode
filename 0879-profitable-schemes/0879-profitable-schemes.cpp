class Solution {
public:
    
// 1
// 1
// [2,2,2,2,2]
// [1,2,1,1,0]
    
        int mod = 1e9 + 7;
    
        int schemes(int i, int n, int minProfit, vector<int> &group, vector<int> &profit, vector<vector<vector<int>>> &dp)
        {
            // cout << minProfit << endl;
            int m = group.size();
            if(n < 0)
                return 0;
            if(i >= m)
                return minProfit <= 0;
            
            if(minProfit <= 0 && dp[i][n][0] != -1)
                return dp[i][n][0];
                
            if(minProfit > 0 && dp[i][n][minProfit] != -1)
                return dp[i][n][minProfit];
            
            if(minProfit <= 0)
            {
                return (dp[i][n][0] = schemes(i+1, n, minProfit, group, profit, dp) + schemes(i+1, n - group[i], minProfit - profit[i], group, profit, dp)) %= mod;
            }
            
            // if(minProfit >= 0)
            // {
                return (dp[i][n][minProfit] = schemes(i+1, n, minProfit, group, profit, dp) + schemes(i+1, n - group[i], minProfit - profit[i], group, profit, dp)) %= mod;
            // }
    }
        
    
        int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
            int m = group.size();
            vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (n+1, vector<int> (minProfit + 1, -1)));
            return schemes(0, n, minProfit, group, profit, dp);
        }
};
    
    
    
//     Runtime: 157 ms, faster than 72.64% of C++ online submissions for Profitable Schemes.
// Memory Usage: 12.8 MB, less than 72.64% of C++ online submissions for Profitable Schemes.
    
    
//     Runtime: 168 ms, faster than 62.74% of C++ online submissions for Profitable Schemes.
// Memory Usage: 12.8 MB, less than 66.51% of C++ online submissions for Profitable Schemes.
    
    // Just copy and paste due to fever and cold
    
    
//      int mod = 1e9 + 7;
//     int memo[101][101][101];
    
//     int find(int pos, int count, int profit, int n, int minProfit, vector<int>& group, vector<int>& profits) {
//         if (pos == group.size()) {
//             // If profit exceeds the minimum required; it's a profitable scheme.
//             return profit >= minProfit;
//         }
        
//         if (memo[pos][count][profit] != -1) {
//             // Repeated subproblem, return the stored answer.
//             return memo[pos][count][profit];
//         }
        
//         // Ways to get a profitable scheme without this crime.
//         int totalWays = find(pos + 1, count, profit, n, minProfit, group, profits);
//         if (count + group[pos] <= n) {
//             // Adding ways to get profitable schemes, including this crime.
//             totalWays += find(pos + 1, count + group[pos], min(minProfit, profit + profits[pos]), n, minProfit, group, profits);
//         }
        
//         return memo[pos][count][profit] = totalWays % mod;
//     }
             
//     int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
//         memset(memo, -1,sizeof(memo));
//         return find(0, 0, 0, n, minProfit, group, profit);
//     }
// };