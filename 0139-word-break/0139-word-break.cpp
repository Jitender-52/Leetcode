class Solution {
public:
    
//     bool dfs(int i, int j, string &s, vector<string> &word, vector<vector<int>> &dp)
//     {
//         int n = s.length();
//         int m = word.size();
//         if(i >= n)
//             return true;
//         if(j >= m)
//             return false;
//         // if(dp[i][j] != -1)
//         //     return dp[i][j];
        
//         int l = word[j].length();
//         if(i + l < n && s.substr(i, l) == word[j])
//         {
//             return dp[i][j] = dfs(i+l, j+1, s, word, dp) || dfs(i, j+1, s, word, dp);
//         }
//         return dp[i][j] = dfs(i, j+1, s, word, dp);
//     }
    
     bool dfs(int i, string &s, vector<string> &word, vector<int> &dp)
     {
         int n = s.length();
         int m = word.size();
         
         if(i >= n)
             return true;
         if(dp[i] != -1)
             return dp[i];
         
         for(int j = 0; j < m; j++)
         {
             int l = word[j].length();
             if(n - i >= l)
             {
                 if(s.substr(i, l) == word[j])
                 {
                     if(dfs(i+l, s, word, dp))
                         return true;
                 }
             }
         }
         return dp[i] = false;
     }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int m = wordDict.size();
        vector<int> dp(n, -1);
        return dfs(0, s, wordDict, dp);
    }
};