class Solution {
public:
    
    int insertions(int i, int j, string &s, vector<vector<int>> &dp)
    {
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == s[j])
            return dp[i][j] = insertions(i+1, j-1, s, dp);
        return dp[i][j] = 1 + min(insertions(i+1, j, s, dp), insertions(i, j-1, s, dp));
    }
    
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n , -1));
        return insertions(0, n-1, s, dp);
    }
};