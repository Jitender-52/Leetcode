class Solution {
public:
    
    int dp[101][101];
    
    int makePalindrome(string s)
    {
        int n = s.length();
        int i = 0, j = n-1, count = 0;
        while(i < j)
        {
            count += s[i] != s[j];
            i++;
            j--;
        }
        return count;
    }
    
    int solve(int i, int count, int k, string s)
    {
        int n = s.length();
        if(i == n)
        {
            if(count == k)
                return 0;
            return 200;
        }
        
        if(dp[i][count] != -1)
            return dp[i][count];

        string x = "";
        int ans = 200;
        for(int j = i; j < n; j++)
        {
            x += s[j];
            ans = min(ans, makePalindrome(x) + solve(j+1, count+1, k, s));
        }
        return dp[i][count] = ans;
    }
    
    int palindromePartition(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, k, s);
    }
};