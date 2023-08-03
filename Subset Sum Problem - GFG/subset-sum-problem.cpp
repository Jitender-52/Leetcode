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

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return subset(0, sum, arr, dp);
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