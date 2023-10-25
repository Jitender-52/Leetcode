//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<int> dp(w + 1, 0);
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 0; j <= w; j++)
            {
                if(wt[i] <= j)
                    dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);      
            }
        }
        int ans = 0;
        for(int i = 0; i <= w; i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
    

//     int knapSack(int n, int w, int val[], int wt[])
//     {
//         // code here
//         vector<vector<int>> dp(n+1, vector<int> (w + 1, 0));
//         for(int i = n-1; i >= 0; i--)
//         {
//             for(int j = 0; j <= w; j++)
//             {
//                 dp[i][j] = dp[i+1][j];
//                 if(wt[i] <= j)
//                     dp[i][j] = max(dp[i][j], val[i] + dp[i][j - wt[i]]);
//                 // for(int k = 0; k <= j / wt[i]; k++)
//                 // {
//                 //     // cout << j - k * wt[i] << endl;
//                 //     dp[i][j] = max(dp[i][j], k * val[i] + dp[i+1][j - k * wt[i]]);
//                 // }
//             }
//         }
//         int ans = 0;
//         for(int j = 0; j <= w; j++)
//             ans = max(ans, dp[0][j]);
//         return ans;
//     }
// };

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends