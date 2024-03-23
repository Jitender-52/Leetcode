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
    
    int solve(int i, int last, int secondlast, int n, vector<vector<vector<int>>> &dp)
    {
        if(i > n)
            return 1;
        if(dp[i][last][secondlast] != -1)
            return dp[i][last][secondlast];
        int ans = 0;
        for(int j = 1; j <= 6; j++)
        {
            if(gcd(j, last) == 1 && j != last && j != secondlast)
                (ans += solve(i+1, j, last, n, dp)) %= mod;
        }
        return dp[i][last][secondlast] = ans;
    }
    
    int distinctSequences(int n) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (7, vector<int> (7, -1)));
        return solve(1, 0, 0, n, dp);
    }
};