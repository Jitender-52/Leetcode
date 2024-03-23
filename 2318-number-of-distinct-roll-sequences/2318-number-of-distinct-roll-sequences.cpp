class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int gcd(int a, int b)
    {
        if(a == 0 || b == 0)
            return 1; // for this code only because if last is zero than gcd will not to be taken or we can consider it 1;
        while (a > 1 && b > 1)
        {
            if (a > b)
            {
                if (a % b == 0)
                    return b;
                a = a % b;
            }
            else
            {
                if (b % a == 0)
                    return a;
                b = b % a;
            }
        }
        return 1;
    }
    
    int distinctSequences(int n) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (7, vector<int> (7, 0)));
        // dp[0][0][0] = 1;
        for(int last = 0; last <= 6; last++)
        {
            for(int secondlast = 0; secondlast <= 6; secondlast++)
            {
                dp[n][last][secondlast] = 1;
            }
        }
        
        for(int i = n-1; i >= 0; i--)
        {
            for(int last = 0; last <= 6; last++)
            {
                for(int secondlast = 0; secondlast <= 6; secondlast++)
                {
                    // dp[i][last][secondlast] = 0;
                    for(int j = 1; j <= 6; j++)
                    {
                        if(gcd(j, last) == 1 && j != last && j != secondlast)
                            (dp[i][last][secondlast] += dp[i+1][j][last]) %= mod;
                    }
                }
            }
        }
        return dp[0][0][0];
    }
};
  

// Not Working

//     int distinctSequences(int n) {
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (7, vector<int> (7, 1)));
//         dp[0][0][0] = 1;
//         int ans = 0;
//         for(int i = 1; i <= n; i++)
//         {
//             for(int last = 0; last <= 6; last++)
//             {
//                 for(int secondlast = 0; secondlast <= 6; secondlast++)
//                 {
//                     dp[i][last][secondlast] = 0;
//                     for(int j = 1; j <= 6; j++)
//                     {
//                         if(gcd(j, last) == 1 && j != last && j != secondlast)
//                             (dp[i][last][secondlast] += dp[i-1][j][last]) %= mod;
//                     }
//                 }
//             }
//         }
        
//         for(int last = 0; last <= 6; last++)
//         {
//             for(int secondlast = 0; secondlast <= 6; secondlast++)
//             {
//                 (ans += dp[n][last][secondlast]) %= mod;
//             }
//         }
//         return ans;
//         return dp[n][6][6];        
//     }
// };
    
    
//     Runtime: 299 ms, faster than 30.00% of C++ online submissions for Number of Distinct Roll Sequences.
// Memory Usage: 109.1 MB, less than 21.82% of C++ online submissions for Number of Distinct Roll Sequences.
    
//     const int mod = 1e9 + 7;
    
//     int gcd(int a, int b)
//     {
//         if(a == 0 || b == 0)
//             return 1; // for this code only because if last is zero than gcd will not to be taken or we can consider it 1;
//         while (a > 1 && b > 1)
//         {
//             if (a > b)
//             {
//                 if (a % b == 0)
//                     return b;
//                 a = a % b;
//             }
//             else
//             {
//                 if (b % a == 0)
//                     return a;
//                 b = b % a;
//             }
//         }
//         return 1;
//     }
    
//     int solve(int i, int last, int secondlast, int n, vector<vector<vector<int>>> &dp)
//     {
//         if(i > n)
//             return 1;
//         if(dp[i][last][secondlast] != -1)
//             return dp[i][last][secondlast];
//         int ans = 0;
//         for(int j = 1; j <= 6; j++)
//         {
//             if(gcd(j, last) == 1 && j != last && j != secondlast)
//                 (ans += solve(i+1, j, last, n, dp)) %= mod;
//         }
//         return dp[i][last][secondlast] = ans;
//     }
    
//     int distinctSequences(int n) {
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (7, vector<int> (7, -1)));
//         return solve(1, 0, 0, n, dp);
//     }
// };