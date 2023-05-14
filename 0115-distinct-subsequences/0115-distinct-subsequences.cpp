class Solution {
public:
    
    int distinct(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        int n = s.length();
        int m = t.length();
        if(j == m)
            return 1;
        if(i >= n || j >= m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        if(s[i] == t[j])
        {
            ans += distinct(i+1, j+1, s, t, dp);
        }
        ans += distinct(i+1, j, s, t, dp);
        return dp[i][j] = ans;
    }
    
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return distinct(0, 0, s, t, dp);
    }
};