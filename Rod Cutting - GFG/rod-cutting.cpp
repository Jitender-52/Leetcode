//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        // vector<vector<int>> dp(n+1, vector<int> (price+1, 0));
        
        vector<int> dp(n + 1, 0);
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                dp[i] = max(dp[i], price[i-1]);
                // // if(i - j > 0)
                dp[i] = max(dp[i], dp[j] + dp[i-j]);
                // dp[j] = max(dp[j], price[i - 1] + dp[]);
                // dp[i][j] = max(dp[i][j], price[x-1] + dp[i][])
            }
        }
        
        // for(int i = 0; i <= n; i++)
        // {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        return dp[n];
        
        // for(int i = n-1; i >= 0; i--)
        // {
        //     for(int j = 0; j <= n; j++)
        //     {
        //         dp[i][j] = max(dp[i][j], price[j] + dp[i+1][]);
        //     }
        // }
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends