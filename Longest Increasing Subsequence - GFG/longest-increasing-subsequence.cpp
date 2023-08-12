//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    
    
    int longestSubsequence(int n, int a[])
    {
        vector<int> temp;
        temp.push_back(a[0]);
        for(int i = 1; i < n; i++)
        {
            auto idx = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
            if(idx >= temp.size())
                temp.push_back(a[i]);
            else
                temp[idx] = a[i];
        }
        return (int)(temp.size());
    }
};
    
    
    
//     int longest(int i, int j, vector<int> &v, vector<vector<int>> &dp)
//     {
//         int n = v.size();
//         if(i >= n)
//             return 0;
//         if(dp[i][j] != -1)
//             return dp[i][j];
//         if(v[i] > v[j])
//             dp[i][j] = max(dp[i][j], 1 + longest(i+1, i, v, dp));
//         dp[i][j] = max(dp[i][j], longest(i+1, j, v, dp));
//         return dp[i][j];
//     }
    
//     int longestSubsequence(int n, int a[])
//     {
//       // your code here
       
//         // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
//         vector<int> v(n+1, -1);
//         for(int i = 0; i < n; i++)
//             v[i+1] = a[i];
//         // return longest(1, 0, v, dp);
        
//         vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
        
//         for(int i = n; i >= 1; i--)
//         {
//             for(int j = 0; j < i; j++)
//             {
//                 if(v[i] > v[j])
//                     dp[i][j] = max(1 + dp[i+1][i], dp[i][j]);
//                 dp[i][j] = max(dp[i][j], dp[i+1][j]);
//             }
//         }
//         return dp[1][0];
//     }
// };

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends