class Solution {
public:
    const int mod = 1e9 + 7;

    int solve(int i, int absentCount, int lateCount, int n, vector<vector<vector<int>>> &dp)
    {
        if (i > n)
            return 1;
        if (dp[i][absentCount][lateCount] != -1)
            return dp[i][absentCount][lateCount];

        int absent = absentCount < 1 ? solve(i + 1, absentCount + 1, 0, n, dp) : 0;
        int late = lateCount < 2 ? solve(i + 1, absentCount, lateCount + 1, n, dp) : 0;
        int present = solve(i + 1, absentCount, 0, n, dp);

        dp[i][absentCount][lateCount] = ((absent + late) % mod + present % mod) % mod;
        return dp[i][absentCount][lateCount];
    }

    int checkRecord(int n)
    {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(4, -1)));
        return solve(1, 0, 0, n, dp);
    }};