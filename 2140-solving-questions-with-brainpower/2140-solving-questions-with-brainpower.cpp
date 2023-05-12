class Solution {
public:
    
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            vector<long long> dp(n+1, 0);
            
            for(int i = n-1; i >= 0; i--)
            {
                if(i + 1 + questions[i][1] >= n)
                    dp[i] = max(dp[i+1], (long long)questions[i][0]);
                else
                    dp[i] = max(dp[i+1], (long long)questions[i][0] + dp[i+1+questions[i][1]]);
            }
            return dp[0];
        }
};
    
    
//     Runtime: 403 ms, faster than 21.35% of C++ online submissions for Solving Questions With Brainpower.
// Memory Usage: 123 MB, less than 44.72% of C++ online submissions for Solving Questions With Brainpower.
    
//     long long points(int i, vector<vector<int>> &questions, vector<long long> &dp)
//     {
//         int n = questions.size();
//         if(i >= n)
//             return 0;
//         if(dp[i] != -1)
//             return dp[i];
//         return dp[i] = max(questions[i][0] + points(i+1+questions[i][1], questions, dp), points(i+1, questions, dp));
//     }
    
//     long long mostPoints(vector<vector<int>>& questions) {
//         int n = questions.size();
//         vector<long long> dp(n, -1);
//         return points(0, questions, dp);        
//     }
// };