class Solution {
public:
    
    int longest(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        int n = s1.length();
        int m = s2.length();
        
        if(i >= n || j >= m)
            return 0;
    
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        
        if(s1[i] == s2[j])
        {
            ans = 1 + longest(i+1, j+1, s1, s2, dp);
        }
        
        ans = max(ans, longest(i+1, j, s1, s2, dp));
        ans = max(ans, longest(i, j+1, s1, s2, dp));
        
        return dp[i][j] = ans;
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return longest(0, 0, text1, text2, dp);
        
    }
};