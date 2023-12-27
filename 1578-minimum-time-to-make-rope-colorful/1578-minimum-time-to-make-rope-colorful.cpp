class Solution {
public:
    
    // map<pair<int,char>, int> mp;
    int dp[100001][27];
    
    int cost(int i, char last, string &colors, vector<int> &neededTime)
    {
        int n = colors.size();
        if(i >= n)
            return 0;
        // if(mp.find({i, last}) != mp.end())
        //     return mp[{i, last}];
        
        if(dp[i][last - 'a' + 1] != -1)
            return dp[i][last - 'a' + 1];
        
        int ans = 1e9;
        ans = min(ans, neededTime[i] + cost(i+1, last, colors, neededTime));
        if(colors[i] != last)
            ans = min(ans, cost(i+1, colors[i], colors, neededTime));
        // return mp[{i, last}] = ans;
        return dp[i][last - 'a' + 1] = ans;
    }
    
    int minCost(string colors, vector<int>& neededTime) {
        for(int i = 0; i < 1e5; i++)
        {
            for(int j = 0; j < 27; j++)
                dp[i][j] = -1;
        }
        char c = 'a';
        c--;
        return cost(0, c, colors, neededTime);
    }
};
    
//     map<pair<int,char>, int> mp;
    
//     int cost(int i, char last, string &colors, vector<int> &neededTime)
//     {
//         int n = colors.size();
//         if(i >= n)
//             return 0;
//         if(mp.find({i, last}) != mp.end())
//             return mp[{i, last}];
//         int ans = 1e9;
//         ans = min(ans, neededTime[i] + cost(i+1, last, colors, neededTime));
//         if(colors[i] != last)
//             ans = min(ans, cost(i+1, colors[i], colors, neededTime));
//         return mp[{i, last}] = ans;
//     }
    
//     int minCost(string colors, vector<int>& neededTime) {
//         return cost(0, '*', colors, neededTime);
//     }
// };