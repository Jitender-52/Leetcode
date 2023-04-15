class Solution {
public:
    
    
    int maxCoins(int i, int k, vector<vector<int>> &v, vector<vector<int>> &dp)
    {
        int n = v.size();
        if(i >= n || k == 0)
            return 0;
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        int ans = 0;
        
        for(int j = 0; j <= k && j < v[i].size(); j++)
        {
            ans = max(ans, v[i][j] + maxCoins(i+1, k-j, v, dp));   
        }
        return dp[i][k] = ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> v;
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            vector<int> help;
            for(int j = 0; j < piles[i].size(); j++)
            {
                help.push_back(sum);
                sum += piles[i][j];
            }
            help.push_back(sum);
            v.push_back(help);
        }
        
        vector<vector<int>> dp(n, vector<int> (k+1, -1));
             
        return maxCoins(0, k, v, dp);
    }
};