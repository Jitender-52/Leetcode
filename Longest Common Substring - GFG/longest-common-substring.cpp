//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m){
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = m-1; j >= 0; j--)
            {
                if(s1[i] == s2[j])
                    dp[i][j] = max(dp[i][j], 1 + dp[i+1][j+1]);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                ans = max(ans, dp[i][j]);
        }
        return ans;
    }
};    

//     int longest(int i, int j, string s1, string s2, int n, int m, vector<vector<int>> &dp)
//     {
//         if(i >= n || j >= m)
//             return 0;
//         if(dp[i][j] != -1)
//             return dp[i][j];
//         int ans = 0;
//         if(s1[i] == s2[j])
//         {
//           ans = 1 + longest(i+1, j+1, s1, s2, n, m, dp);
//         }
//         longest(i+1, j, s1, s2, n, m, dp);
//         longest(i, j+1, s1, s2, n, m, dp);
//         return dp[i][j] = ans;
//     }
    
//     int longestCommonSubstr (string s1, string s2, int n, int m)
//     {
//         // your code here
//         vector<vector<int>> dp(n, vector<int> (m, -1));
//         longest(0, 0, s1, s2, n, m, dp);
//         int ans = 0;
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//                 ans = max(ans, dp[i][j]);
//         }
//         return ans;
//     }
// };

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends