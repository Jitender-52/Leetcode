//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool partition(int i, int n, int sum, int sum2, int nums[], vector<vector<int>> &dp)
    {
        if(i == n)
        {
            return sum == sum2;
        }
        if(i >= n)
            return 0;
        
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        bool ans = false;
        ans = ans | partition(i+1, n,  sum + nums[i], sum2, nums, dp);
        ans = ans | partition(i+1, n, sum, sum2 + nums[i], nums, dp);
        return dp[i][sum] = ans;
    }

    int equalPartition(int n, int nums[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += nums[i];
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return partition(0, n, 0, 0, nums, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends