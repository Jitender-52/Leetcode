class Solution {
public:
    
    long long dp[100001][2];
    
    long long solve(int i, int j, vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        if(i >= n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        long long ans = 0;
        if(j == 0)
            ans = max(ans, a[i] + max(solve(i+1, j, a, b), solve(i+2, 1, a, b)));
        else
            ans = max(ans, b[i] + max(solve(i+1, j, a, b), solve(i+2, 0, a, b)));
        return dp[i][j] = ans;
    }
    
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB)     {
        memset(dp, -1, sizeof(dp));
        return max(solve(0, 0, energyDrinkA, energyDrinkB), solve(0, 1, energyDrinkA, energyDrinkB));
    }
};