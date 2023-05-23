class Solution {
public:
    
    
    int numTrees(int n) {
        vector<int> dp(n+1);
        
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                dp[i] += dp[j-1] * dp[i-j];       
            }
        }
        return dp[n];
    }
};
    
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Binary Search Trees.
// Memory Usage: 6 MB, less than 41.20% of C++ online submissions for Unique Binary Search Trees.
    
//     int Trees(int n, vector<int> &dp)
//     {
//         if(n == 1 || n == 0)
//             return 1;
//         if(dp[n] != -1)
//             return dp[n];
//         int ans = 0;
//         for(int i = 1; i <= n; i++)
//         {
//             ans += Trees(i-1, dp) * Trees(n-i, dp);
//         }
//         return dp[n] = ans;
//     }
    
//     int numTrees(int n) {
//         vector<int> dp(n+1, -1);
//         int ans = 0;
//         return Trees(n, dp);
//     }
// };