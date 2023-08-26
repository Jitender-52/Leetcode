class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int last = 0; last < i; last++)
            {
                if(pairs[i][0] > pairs[last][1])
                    dp[i] = max(dp[i], dp[last] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};