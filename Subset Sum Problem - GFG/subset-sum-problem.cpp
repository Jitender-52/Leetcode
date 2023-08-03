//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool subset(int i, int sum, vector<int> &arr, vector<vector<int>> &dp)
    {
        int n = arr.size();
        if(sum == 0)
            return true;
        if(sum <  0)
            return false;
        if(i >= n)
            return false;
            
        if(dp[i][sum] != -1)
            return dp[i][sum];
            
        if(subset(i+1, sum - arr[i], arr, dp) || subset(i+1, sum, arr, dp))
            return true;
        // return false;
        return dp[i][sum] = false;
    }

    bool isSubsetSum(vector<int>arr, int target){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (target+1, 0));
        // return subset(0, target, arr, dp);
        
        for(int i = 0; i < n; i++)
            dp[i][0] = 1;
        if(arr[0] <= target)
            dp[0][arr[0]] = 1;
       
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= target; j++)
            {
               dp[i][j] = (dp[i-1][j]) | ((arr[i] <= j) ? dp[i-1][j-arr[i]] : false);
            }
        }
        return dp[n-1][target];
        
        // for(int i = 1; i < n; i++)
        // {
        //     for(int j = 0; j <= target; j++)
        //     {
        //         bool take = false;
        //         if(arr[i] <= j)
        //             take = dp[i-1][j - arr[i]];
        //         bool notTake = dp[i-1][j];
        //         dp[i][j] = take || notTake;
        //     }
        // }
        // return dp[n-1][target];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends