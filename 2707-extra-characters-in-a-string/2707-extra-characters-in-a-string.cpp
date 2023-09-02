class Solution {
public:
    
    int solve(int i, string s, vector<string> &dictionary, vector<int> &dp)
    {
        int n = s.length();
        int m = dictionary.size();
        
        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int ans = n - i;
        
        for(int k = i; k < n; k++)
        {
            for(int j = 0; j < m; j++)
            {
                int a = dictionary[j].length();
                if(a > n-k)
                    continue; // my bad used break here
                if(s.substr(k, a) == dictionary[j])
                {
                    ans = min(ans, k-i + solve(k+a, s, dictionary, dp));
                }
            }
        }
        return dp[i] = ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        int m = dictionary.size();
        
        vector<int> dp(n, -1);
        
        return solve(0, s, dictionary, dp);
        
    }
};
    
    
//     int minimum(int i, string &s, vector<string> &dictionary, vector<int> &dp)
//     {
//         int n = s.length();
//         int m = dictionary.size();
//         if(i >= n)
//         {
//             return 0;
//         }
        
//         if(dp[i] != -1)
//             return dp[i];
        
//         int ans = n - i;
//         for(int k = i; k < n; k++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 int a= dictionary[j].length();
//                 string x = s.substr(k, a);
//                 // cout << x << " " << dictionary[j] << endl;
//                 if(a + k > n)
//                     continue;
//                 if(x == dictionary[j])
//                 {
//                     // cout << x << " " << dictionary[j] << endl;
//                     // cout << k + a << endl;
//                     ans = min(ans, k - i + minimum(k + a, s, dictionary, dp));
//                 }
//             }
//         }
//         return dp[i] =  ans;
//     }
    
//     int minExtraChar(string s, vector<string>& dictionary) {
//         int n = s.length();
//         int m = dictionary.size();
        
//         // sort(dictionary.rbegin(), dictionary.rend());
//         vector<int> dp(n+5, -1);
//         return minimum(0, s, dictionary, dp);
        
//         // for(int i = 0; i < n; i++)
//         // {
//         //     for(int j = 0; j < )
//         // }
        
//     }
// };