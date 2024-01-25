class Solution {
public:
    
    vector<vector<int>> dp;
    int common(int i, int j, string &text1, string &text2)
    {
        int n = text1.length();
        int m = text2.length();
        if(i >= n || j >= m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(text1[i] == text2[j])
            return 1 + common(i+1, j+1, text1, text2);
        return dp[i][j] = max(common(i+1, j, text1, text2), common(i, j+1, text1, text2));
    }
          
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        dp.resize(n, vector<int> (m, -1));
        return common(0, 0, text1, text2);
    }
};