class Solution {
public:
    
    int solve(int i, int count, int last, int target, vector<int> &houses,
              vector<vector<int>> &cost, vector<vector<vector<int>>> &dp)
    {
        int m = cost.size();
        int n = cost[0].size();
        if(count > target)
            return 1e9;
        if(i == m)
        {
            if(count != target)
                return 1e9;
            return 0;
        }
        
        if(dp[i][count][last] != -1)
            return dp[i][count][last];
        
        int ans = 1e9;
        if(i == 0)
        {
            if(houses[i] != 0)
            {
                ans = min(ans, solve(i+1, count+1, houses[i], target, houses, cost, dp));
            }
            else
            {
                for(int j = 0; j < n; j++)
                {
                    houses[i] = j+1;
                    ans = min(ans, cost[i][j] + solve(i+1, count+1, houses[i], target, houses, cost, dp));
                    houses[i] = 0;
                }
            }
        }
        else
        {
            if(houses[i] != 0)
            {
               if(houses[i] != houses[i-1])
                   ans = min(ans, solve(i+1, count+1, houses[i], target, houses, cost, dp));
               else
                   ans = min(ans, solve(i+1, count, houses[i], target, houses, cost, dp));
            }
            else
            {
                for(int j = 0; j < n; j++)
                {
                    houses[i] = j+1;
                    if(houses[i] != houses[i-1])
                        ans = min(ans, cost[i][j] + solve(i+1, count+1, houses[i], target, houses, cost, dp));
                    else
                        ans = min(ans, cost[i][j] + solve(i+1, count, houses[i], target, houses, cost, dp));
                    houses[i] = 0;
                }
            }
        }
        return dp[i][count][last] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // vector<vector<int>> dp(m+1, vector<int> (target+1, -1));
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (target+1, vector<int> (n+1, -1)));
        int ans = solve(0, 0, 0, target, houses, cost, dp);
        return ans == 1e9 ? -1 : ans;
    }
};