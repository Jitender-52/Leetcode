class Solution {
public:
    
//     Runtime: 57 ms, faster than 29.34% of C++ online submissions for Strange Printer.
// Memory Usage: 12.2 MB, less than 17.20% of C++ online submissions for Strange Printer.
    
  int dp[1001][1001];
    int f(int i, int j, string &s)
    {
        if(dp[i][j] != -1)
            return dp[i][j];
        int minTurns = INT_MAX;
        if(i == j)
            return 1;
        
        for(int k = i; k < j; k++)
            minTurns = min(minTurns, f(i, k, s) + f(k+1, j, s));
        if(s[i] == s[j])
            minTurns--;
        return dp[i][j] = minTurns;
    }

    int strangePrinter(string s) 
    {
        memset(dp, -1, sizeof(dp));
        return f(0, s.length()-1, s);
    }
};