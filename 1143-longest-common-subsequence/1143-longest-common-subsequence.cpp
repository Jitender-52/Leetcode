class Solution {
public:
    
    
        int longestCommonSubsequence(string text1, string text2) {
            int n = text1.length();
            int m = text2.length();
            
            vector<int> curr(m+1, 0);
            vector<int> prev(m+1, 0);
            
            for(int i = n-1; i >= 0; i--)
            {
                for(int j = m-1; j >= 0; j--)
                {
                    if(text1[i] == text2[j])
                    {
                        curr[j] = max(curr[j], 1 + prev[j+1]);
                    }
                    else
                    {
                        curr[j] = max(curr[j], prev[j+1]);
                        curr[j] = max(curr[j], curr[j+1]);
                    }
                }
                prev = curr;
            }
            return curr[0];
        }
};
    
    
//     Runtime: 65 ms, faster than 9.32% of C++ online submissions for Longest Common Subsequence.
// Memory Usage: 18.6 MB, less than 26.34% of C++ online submissions for Longest Common Subsequence.
    
//     int longestCommonSubsequence(string text1, string text2) {
        
//         int n = text1.length();
//         int m = text2.length();
        
//         vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
//         for(int i = n-1; i >= 0; i--)
//         {
//             for(int j = m-1; j >= 0; j--)
//             {
//                 if(text1[i] == text2[j])
//                 {
//                     dp[i][j] = max(dp[i+1][j+1] + 1, dp[i][j]);
//                 }
//                 else
//                 {
//                     dp[i][j] = max(dp[i][j], dp[i+1][j]);
//                     dp[i][j] = max(dp[i][j], dp[i][j+1]);
//                 }
//             }
//         }
//         return dp[0][0];
//     }
// };
    
    
//     Runtime: 107 ms, faster than 5.09% of C++ online submissions for Longest Common Subsequence.
// Memory Usage: 19 MB, less than 6.62% of C++ online submissions for Longest Common Subsequence.
    
//     int longest(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
//     {
//         int n = s1.length();
//         int m = s2.length();
        
//         if(i >= n || j >= m)
//             return 0;
    
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         int ans = 0;
        
//         if(s1[i] == s2[j])
//         {
//             ans = 1 + longest(i+1, j+1, s1, s2, dp);
//         }
        
//         ans = max(ans, longest(i+1, j, s1, s2, dp));
//         ans = max(ans, longest(i, j+1, s1, s2, dp));
        
//         return dp[i][j] = ans;
        
//     }
    
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.length();
//         int m = text2.length();
        
//         vector<vector<int>> dp(n, vector<int> (m, -1));
        
//         return longest(0, 0, text1, text2, dp);
        
//     }
// };