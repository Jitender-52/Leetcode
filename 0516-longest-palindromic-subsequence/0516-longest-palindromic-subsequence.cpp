class Solution {
public:
    
    int longest(int i, int j, string &s, vector<vector<int>> &dp)
    {
        int n = s.length();
        
        if(i == j)
            return 1;
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == s[j])
            return dp[i][j] = 2 + longest(i+1, j-1, s, dp);
        
        return dp[i][j] = max(longest(i+1, j, s, dp), longest(i, j-1, s, dp));     
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return longest(0, n-1, s, dp);
    }
};