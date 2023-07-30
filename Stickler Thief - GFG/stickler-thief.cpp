//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int solve(int i, int arr[], int n, vector<int> &dp)
    {
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = max(arr[i] + solve(i+2, arr, n, dp), solve(i+1, arr, n, dp));
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n+2, 0);
        // return solve(0, arr, n, dp);
        
        // for(int i = 0; i < n; i++)
        // {
        //     dp[i] = arr[i];
        //     if(i - 1 >= 0)
        //         dp[i] = max(dp[i], dp[i-1]);
        //     if(i - 2 >= 0)
        //         dp[i] = max(dp[i], arr[i] + dp[i-2]);
        // }
        // return dp[n-1];
        
        for(int i = n-1; i >= 0; i--)
        {
            dp[i] = max(dp[i+1], arr[i] + dp[i+2]);
        }
        return dp[0];
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends