//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int i, int w, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        if(i < 0)
        {
              return 0;          
        }
        if(dp[i][w] != -1)
            return dp[i][w];
            
        int notTake = solve(i-1, w, wt, val, n, dp);
        int take = INT_MIN;
        if(wt[i] <= w)
            take = val[i] + solve(i-1, w-wt[i], wt, val, n, dp);
        return dp[i][w] = max(take, notTake);
    }
    
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       
    //   vector<vector<int>> dp(n, vector<int> (w+1, -1));
    //   return solve(n-1, w, wt, val, n, dp);
    
        vector<vector<int>> dp(n+1, vector<int> (w+1, 0));
        
        // for(int i = 0; i < n; i++)
        // {
        //     if(wt[i] <= w)
        //         dp[0][wt[i]] = val[0];
        // }
        
        for(int i = wt[0]; i <= w; i++)
            dp[0][i] = val[0];
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= w; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j-wt[i] >= 0)
                    dp[i][j] = max(dp[i][j], val[i] + dp[i-1][j-wt[i]]);
            }
        }
        return dp[n-1][w];
        int ans = 0;
        // for(int i = 0; i <= w; i++)
        // {
        //     ans = max(ans, dp[n-1][w]);
        // }
        // return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends