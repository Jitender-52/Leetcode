class Solution {
public:
    
    const int mod = 1e9+7;
    
    int routes(int start, int finish, int fuel, vector<int> &locations, vector<vector<int>> &dp)
    {
        int n = locations.size();
        if(fuel < 0)
            return 0;
        if(dp[start][fuel] != -1)
            return dp[start][fuel];
        
        int ans = 0;
        if(start == finish)
            ans++;
        for(int i = 0; i < n; i++)
        {
            if(i != start)
            {
                (ans += routes(i, finish, fuel - abs(locations[i] - locations[start]), locations, dp)) %= mod;
            }
        }
        return dp[start][fuel] = ans;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int> (fuel+1, -1));
        return routes(start, finish, fuel, locations, dp);
    }
};