//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  
    int solve(int i, int target, vector<int> &a, vector<vector<int>> &dp)
    {
        int n = a.size();
        if(i >= n)
            return target == 0 ? 1 : 0;
        // if(dp[i][target] != -1)
        //     return dp[i][target + 1e4];
        return solve(i + 1, target + a[i], a, dp) + solve(i + 1, target - a[i], a, dp);
    }
  
    int findTargetSumWays(vector<int>&a, int target) {
        //Your code here
        int n = a.size();
        vector<vector<int>> dp(n, vector<int> (1e4, -1));
        return solve(0, target, a, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends