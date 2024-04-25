class Solution {
public:
    
    int dp[100001][26];
    
    int solve(int i, int last, string &s, int k)
    {
        int n = s.length();
        if(i >= n)
            return 0;
        if(dp[i][last] != -1)
            return dp[i][last];
        int ans = 0;
        if(abs(s[i] - 'a' - last) <= k)
            ans = 1 + max(ans, solve(i+1, s[i] - 'a', s, k));
        ans = max(ans, solve(i+1, last, s, k));
        return dp[i][last] = ans;
    }
    
    int longestIdealString(string s, int k) {
        memset(dp, -1, sizeof dp);
        int ans = 0;
        for(int i = 0; i < 26; i++)
            ans = max(ans, solve(0, i, s, k));
        return ans;
    }
};