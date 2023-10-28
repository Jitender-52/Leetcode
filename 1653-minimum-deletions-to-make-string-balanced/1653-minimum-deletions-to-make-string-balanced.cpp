class Solution {
public:
    
    vector<vector<int>> dp;
    int minimum(int i, int j, string &s)
    {
        int n = s.length();
        if(i >= n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == 'b')
        {
            if(j == 0)
                return dp[i][j] = minimum(i+1, j, s);
            else
                return dp[i][j] = min(1 + minimum(i+1, j, s), minimum(i+1, j-1, s));
        }
        else
        {
            if(j == 0)
                return dp[i][j] = min(n - i, 1 + minimum(i+1, j, s)); // mybad used n-i-1
            else
                return dp[i][j] = minimum(i+1, j, s);
        }
        // return dp[i][j] = minimum(i+1, j, s);
    }
    
    int minimumDeletions(string s) {
        int n = s.length();
        dp.resize(n+1, vector<int> (2, -1));
        return minimum(0, 1, s);
    }
};