class Solution {
public:
    
    int numSquares(int n) {
        int sq = sqrt(n);
        
        if((sq * sq) == n)
            return 1;

        while(n % 4 == 0)
        {
            n /= 4;
        }
        
        if(n % 8 == 7)
            return 4;
        
        for(int i = 1; i * i <= n; i++)
        {
            int a = sqrt(n - (i * i));
            if(a * a == n - i * i)
            // if(sqrt(n - i * i) * sqrt(n - i * i) == n - i * i)
                return 2;
        }
        return 3;
    }
};
    
//     int dp[1001]; 
//     int solve(int n)
//     {
//         if(n == 1 || n == 0)
//             return n;
//         if(dp[n] != -1)
//             return dp[n];
//         int ans = 1e4;
//         for(int i = 1; i * i <= n; i++)
//             ans = min(ans, 1 + solve(n - i * i));
//         return dp[n] = ans;
//     }
        
//     int numSquares(int n) {
//         memset(dp, -1, sizeof(dp));
//         return solve(n);
//     }
// };