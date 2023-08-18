//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    // Your code goes here
	    int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int total = sum;
        sum++;
        sum /= 2;
        
        // To learn the tabulation method go here https://leetcode.com/problems/partition-equal-subset-sum/submissions/
        
        vector<vector<int>> dp(n+1, vector<int> (sum+1, 0));
        // dp[n-1][nums[n-1]] = 1;
        // for(int i = n-2; i >= 0; i--)
        // {
        //     for(int j = 0; j <= sum; j++)
        //     {
        //         dp[i][j] = dp[i+1][j];
        //         if(j + nums[i] <= sum)
        //             dp[i][j] |= dp[i+1][j+nums[i]];
        //     }
        // }
        
        if(nums[0] <= sum)
            dp[0][nums[0]] = 1;
        for(int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                dp[i][j] |= dp[i-1][j];
                if(j - nums[i] >= 0)
                    dp[i][j] |= dp[i-1][j-nums[i]];
            }
        }
        
        // for(int i = 0; i <= n; i++)
        // {
        //     for(int j = 0; j <= sum; j++)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        
        int ans = total;
        for(int i = 0; i <= sum; i++)
        {
            if(dp[n-1][i])
            {
                // cout << i << endl;
                ans = min(ans, abs((total - i) - i));
            }
        }
        return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends