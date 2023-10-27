//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{
  public:
  
  int minimumNumberOfDeletions(string s) { 
        // code here
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
            
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = i+1; j < n; j++)
            {
                if(s[i] == s[j])
                    dp[i][j] = max(dp[i][j], 2 + dp[i+1][j-1]);
                else
                    dp[i][j] = max(dp[i][j], max(dp[i+1][j], dp[i][j-1]));
            }
        }
        return n - dp[0][n-1];
        
        // for(int i = 0; i <= n; i++)
        // {
        //     dp[0][i] = 1;
        // }
        
        // for(int i = 1; i < n; i++)
        // {
        //     for(int j = n-1; j >= i; j--)
        //     {
        //         if(i == j)
        //             dp[i][j] = max(dp[i][j], 1 + dp[i-1][j+1]);
        //         else if(s[i] == s[j])
        //             dp[i][j] = max(dp[i][j], 2 + dp[i-1][j+1]);
        //         else
        //             dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j+1]));
        //     }
        // }
        // return dp[n-1][0];
    } 
};
  
//     vector<vector<int>> dp;
//     // int dp[1001][1001];
//     string s;
//     int minimum(int i, int j)
//     {
//         if(i == j)
//             return 1;
//         if(i > j)
//             return 0;
//         if(dp[i][j] != -1)
//             return dp[i][j];
//         if(s[i] == s[j])
//             return dp[i][j] = 2 + minimum(i+1, j-1);
//         return dp[i][j] = max(minimum(i+1, j), minimum(i, j-1));
//     }
  
//     int minimumNumberOfDeletions(string S) { 
//         // code here
//         s = S;
//         int n = s.length();
//         dp.resize(n+1, vector<int>(n+1, -1));
//         // for(int i = 0; i <= 1000; i++)
//         // {
//         //     for(int j = 0; j <= 1000; j++)
//         //         dp[i][j] = -1;
//         // }
//         return n - minimum(0, n-1);
//     } 
// };

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends