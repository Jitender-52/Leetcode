class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    long long ways(int i, int steps, int arrLen, vector<vector<int>> &dp)
    {
        // cout << i << " " << steps << endl;
        if(steps == 0)
        {
            if(i == 0)
                return 1;
            return 0;
        }
        if(dp[i][steps] != -1)
            return dp[i][steps];
        if(i == arrLen-1 && i > 0)
        {
            return dp[i][steps] = (ways(i-1, steps-1, arrLen, dp) + ways(i, steps-1, arrLen, dp)) % mod;
        }
        if(i == 0 && i < arrLen-1)
        {
            return dp[i][steps] = (ways(i, steps-1, arrLen, dp) + ways(i+1, steps-1, arrLen, dp)) % mod;
        }
        if(i != 0 && i != arrLen-1)
            return dp[i][steps] = (ways(i-1, steps-1, arrLen, dp) + ways(i, steps-1, arrLen, dp) + ways(i+1, steps-1, arrLen, dp)) % mod;
        return dp[i][steps] = ways(i, steps-1, arrLen, dp);
    }
    
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps);
        vector<vector<int>> dp(arrLen+1, vector<int> (steps+1, -1));
        return ways(0, steps, arrLen, dp);  
    }
};