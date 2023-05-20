class Solution {
public:
    
    bool isPalindrome(int i, int j, string &s)
    {
        while(i < j)
        {
            if(s[i] != s[j])return 0;
            i++, j--;
        }
        return 1;
    }
    
    int cuts(int i, int j, string &s, vector<int> &dp)
    {
        int n = s.length();
        if(i >= j || isPalindrome(i, j, s))
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        for(int k = i; k < j; k++)
        {
            if(isPalindrome(i, k, s))
            {
                ans = min(ans, 1 + cuts(k+1, j, s, dp));
            }
        }
        return dp[i] = ans;
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return cuts(0, n-1, s, dp);
    }
};
    
    
//     bool isPalindrome(string &s)
//     {
//         int n = s.length();
//         for(int i = 0; i < n/2; i++)
//         {
//             if(s[i] != s[n-i-1])
//             {
//                 return 0;
//             }
//     }
//         return 1;
//     }
    
//     int cuts(string &s, map<string, int> &mp)
//     {
//         int n = s.length();
//         if(n == 1)
//             return 0;
//         if(isPalindrome(s))
//             return 0;
        
//         if(mp.find(s) != mp.end())
//             return mp[s];
           
//         int ans = 1e9;
//         for(int i = 1; i < n; i++)
//         {
//             string x = s.substr(0, i);
//             string y = s.substr(i);
//             ans = min(ans, 1 + cuts(x, mp) + cuts(y, mp));
//             // ans = min(ans, 1 + cuts(s.substr(0, i), mp) + cuts(s.substr(i)), mp));
//         }
//         return mp[s] = ans;
//     }
    
//     int minCut(string s) {
//         int n = s.length();
//         // vector<vector<int>> dp(n, vector<int> (m, -1));
//         map<string, int> mp;
//         return cuts(s , mp);
//     }
// };