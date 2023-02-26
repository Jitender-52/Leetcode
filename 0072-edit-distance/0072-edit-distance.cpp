class Solution {
public:
    
    
    // Solve Using Tabulation Method Also
    
    // Solved using solution 
    //     Try again
    
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for(int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cout << word1[i-1] <<  " " << word2[j-1];
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;   
                }
            }
        }
        return dp[n][m];
    }
};
    
    
    
    
//     Runtime: 9 ms, faster than 81.38% of C++ online submissions for Edit Distance.
// Memory Usage: 8.9 MB, less than 63.20% of C++ online submissions for Edit Distance.
    
//     int minimum(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
//     {
//         int n = word1.size(); 
//         int m = word2.size();
        
//         if(i == n)
//             return m - j;
//         if(j == m)
//             return n - i;
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         if(word1[i] == word2[j])
//             return dp[i][j] = minimum(i+1, j+1, word1, word2, dp);
        
//         return dp[i][j] = min({1 + minimum(i+1, j+1, word1, word2, dp), 1 + minimum(i+1, j, word1, word2, dp), 1 + minimum(i, j+1, word1, word2, dp)});
        
//     }
    
    
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
//         vector<vector<int>> dp(n, vector<int> (m, -1));
        
//         return minimum(0, 0, word1, word2, dp);
        
//     }
// };