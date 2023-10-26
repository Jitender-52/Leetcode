//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
  
    int minOperation(int n)
    {
        int ans = 0;
        while(n != 0)
        {
            if(n % 2 == 0)
                n /= 2;
            else
                n--;
            ans++;
        }
        return ans;
    }
};
  
//     int minOperation(int n)
//     {
//         //code here.
//         vector<int> dp(n+1, 1e9);
//         dp[0] = 0;
//         for(int i = 0; i <= n; i++)
//         {
//             if(i - 1 >= 0)
//                 dp[i] = min(dp[i], 1 + dp[i-1]);
//             if(i % 2 == 0)
//                 dp[i] = min(dp[i], 1 + dp[i/2]);
//         }
//         return dp[n];
//     }
// };

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends