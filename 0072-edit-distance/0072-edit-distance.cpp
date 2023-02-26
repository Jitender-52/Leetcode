class Solution {
public:
    
    int minimum(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        int n = word1.size(); 
        int m = word2.size();
        
        if(i == n)
            return m - j;
        if(j == m)
            return n - i;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(word1[i] == word2[j])
            return dp[i][j] = minimum(i+1, j+1, word1, word2, dp);
        
        return dp[i][j] = min({1 + minimum(i+1, j+1, word1, word2, dp), 1 + minimum(i+1, j, word1, word2, dp), 1 + minimum(i, j+1, word1, word2, dp)});
        
    }
    
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return minimum(0, 0, word1, word2, dp);
        
    }
};