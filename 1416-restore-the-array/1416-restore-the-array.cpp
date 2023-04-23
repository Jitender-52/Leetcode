class Solution {
public:
    
    int mod = 1e9 + 7;
    
    int ways(int i, string &s, int k, vector<int> &dp)
    {
        int n = s.length();
        if(i == n)
            return 1;
        
        if(s[i] == '0')
            return 0;
        
        if(dp[i] != -1)
        {
            return dp[i];
        }
        
        long long ans = 0;
        long long num = 0;
        
        for(int j = i; j < n; j++)
        {
            num = num * 10 +  (s[j] - '0');
            if(num > k)
                break;
            (ans += ways(j+1, s, k, dp)) %= mod;
        }
        return dp[i] = ans;
    }
        
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n, -1);
        return ways(0, s, k, dp);
    }
};