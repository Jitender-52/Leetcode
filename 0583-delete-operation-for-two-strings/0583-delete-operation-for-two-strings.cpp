class Solution {
public:
    
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> prev(m+1, 0);
        for(int i = 0; i <= n; i++)
        {
            vector<int> curr(m+1, 0);
            for(int j = 0; j <= m; j++)
            {
                if(i == 0 || j == 0)
                    curr[j] = i + j;
                else if(word1[i-1] == word2[j-1])
                    curr[j] = prev[j-1];
                else
                    curr[j] = 1 + min(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};
    
    
    
//     Runtime: 635 ms, faster than 8.80% of C++ online submissions for Delete Operation for Two Strings.
// Memory Usage: 376.5 MB, less than 5.94% of C++ online submissions for Delete Operation for Two Strings.
    
//     int solve(int i, int j, string word1, string word2, vector<vector<int>> &dp)
//     {
//         int n = word1.length(), m = word2.length();
//         if(i >= n || j >= m)
//             return 0;
//         if(dp[i][j] != -1)
//             return dp[i][j];
//         if(word1[i] == word2[j])
//             return dp[i][j] = 2 + solve(i+1, j+1, word1, word2, dp);
//         return dp[i][j] = max(solve(i+1, j, word1, word2, dp), solve(i, j+1, word1, word2, dp));
//     }
    
//     int minDistance(string word1, string word2) {
//         int n = word1.length(), m = word2.length();
//         vector<vector<int>> dp(n, vector<int> (m, -1));
//         return n + m - solve(0, 0, word1, word2, dp);
//     }
// };