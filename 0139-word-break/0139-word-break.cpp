class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = s.length();
        set<string> st;
        for(auto i : wordDict)
        {
            st.insert(i);
        }
        
        vector<bool> dp(m+1, 0);
        dp[0] = 1;
        for(int i = 0; i < m; i++)
        {
            if(dp[i] == 1)
            {
                for(int j = 1; j <= m-i; j++)
                {
                    string x = s.substr(i, j);
                    if(st.find(x) != st.end())
                        dp[i+j] = 1;
                }
            }
        }
        return dp[m];
    }
};