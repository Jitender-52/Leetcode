class Solution {
public:
    
    static bool cmpare(pair<int, int> &a, pair<int, int> &b)
    {
        if(a.first == b.first)
            return b.second > a.second;
        return a.first < b.first;
    }
    
//     int maximum(int i, int last, vector<pair<int,int>> &v, vector<int> &dp)
//     {
//         int n = v.size();
//         if(i >= n)
//             return 0;
//         if(v[i].second < last)
//             return 0;
        
//         if(dp[i] != -1)
//             return dp[i];
        
//         int ans = last;
//         ans = max(ans, maximum(i, last, v, dp));
//         ans = max(ans, maximum(i+1, last, v, dp);
//         return dp[i] = ans;
//     }
    
    
    int maximum(int i, vector<pair<int,int>> &v, vector<int> &dp)
    {
        int n = v.size();
        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int ans = 0;
        for(int j = i+1; j < n; j++)
        {
            if(v[j].second >= v[i].second)
            {
                ans = max(ans, v[j].second + maximum(j, v, dp));
            }
        }
        return dp[i] = ans;
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> v;
        
        for(int i = 0; i < n; i++)
        {
            v.push_back({ages[i], scores[i]});
        }
        
        sort(v.begin(), v.end(), cmpare);
        
//         for(int i = 0; i < n; i++)
//         {
//             cout << v[i].first << " " << v[i].second << endl;
//         }
        
        vector<int> dp(n+1, -1);
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, v[i].second + maximum(i, v, dp));
        }
        return ans;
        // return maximum(0, 0, v, dp);
        
        // return 0;
        
    }
};