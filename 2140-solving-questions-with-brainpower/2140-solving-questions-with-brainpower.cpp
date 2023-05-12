class Solution {
public:
    
    long long points(int i, vector<vector<int>> &questions, vector<long long> &dp)
    {
        int n = questions.size();
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = max(questions[i][0] + points(i+1+questions[i][1], questions, dp), points(i+1, questions, dp));
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return points(0, questions, dp);        
    }
};