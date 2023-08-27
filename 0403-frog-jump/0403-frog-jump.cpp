class Solution {
public:
    
    bool cross(int i, int k, vector<int> &stones, vector<vector<int>> &dp)
    {
        int n = stones.size();
        if(i == n-1)
            return true;
        if(i >= n)
            return false;
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        bool ans = false;
        for(int j = i+1; j < n; j++)
        {
            for(int l = max(1, k-1); l <= k+1; l++)
            {
                if(stones[j] - stones[i] == l)
                    ans |= cross(j, l, stones, dp);
            }
        }
        return dp[i][k] = ans;
    }
    
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return cross(0, 0, stones, dp);        
    }
};