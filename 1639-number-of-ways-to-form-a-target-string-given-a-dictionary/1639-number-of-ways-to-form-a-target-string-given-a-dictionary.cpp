class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    long long ways(int i, int j, vector<string> &words, string &target, vector<vector<int>> &dp, vector<vector<int>> &v)
    {
        if(i == target.length())
            return 1;
        
        if(j == words[0].size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        long long ans = 0;
        // for(int k = 0; k < words.size(); k++)
        // {
        //     for(int l = j; l < words[k].size(); l++)
        //     {
        //         if(words[k][l] == target[i])
        //         {
        //             (ans += ways(i+1, l+1, words, target, dp)) %= mod;
        //         }
        //     }
        // }
        
        (ans += ways(i, j+1, words, target, dp, v)) %= mod;
        (ans += ways(i+1, j+1, words, target, dp, v) * v[target[i] - 'a'][j]) %= mod;
        
        return dp[i][j] = ans;
    }
    
    int numWays(vector<string>& words, string target) {
        int m = target.length();
        int n = words[0].size();
        
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        vector<vector<int>> v(26, vector<int> (n+1, 0));
        
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < n; j++)
            {
                v[words[i][j] - 'a'][j]++;
            }
        }
        
        return ways(0, 0, words, target, dp, v);
    }
};