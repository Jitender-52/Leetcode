//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
  
//   Space Optimaization Methdo

    int minDifference(int arr[], int n)  { 
    
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
    
        vector<int> prev(sum+1, 0);
        prev[sum] = 1;
        for(int i = n-1; i >= 0; i--)
        {
            vector<int> curr(sum+1, 0);
            for(int j = 0; j <= sum; j++)
            {
                int notTake = prev[j];
                bool take = false;
                if(j + arr[i] <= sum)
                    take = prev[j+arr[i]];
                curr[j] = take | notTake;
            }
            prev = curr;
        }
        
        int ans = sum;
        for(int i = 0; i <= sum; i++)
        {
            if(prev[i])
                ans = min(ans, abs((sum -i ) - i));
        }
        return ans;
    }
};
  
  
  
  
  
  
  
  
  
  
  
//   Tabulation Method
  
// 	int minDifference(int nums[], int n)  { 
// 	    // Your code goes here
// 	    int sum = 0;
//         for(int i = 0; i < n; i++)
//         {
//             sum += nums[i];
//         }
//         int total = sum;
//         // sum++;
//         // sum /= 2;
        
//         // To learn the tabulation method go here https://leetcode.com/problems/partition-equal-subset-sum/submissions/
        
//         // This may get accepted in full sum let's check and in case of half it will be failed
        
//         vector<vector<int>> dp(n+1, vector<int> (sum+1, 0));
//         dp[n][sum] = 1;
//         for(int i = n-1; i >= 0; i--)
//         {
//             for(int j = 0; j <= sum; j++)
//             {
//                 dp[i][j] = dp[i+1][j];
//                 if(j + nums[i] <= sum)
//                     dp[i][j] |= dp[i+1][j+nums[i]];
//             }
//         }
        
//         int ans = total;
//         for(int i = 0; i <= sum; i++)
//         {
//             if(dp[0][i])
//             {
//                 // cout << i << endl;
//                 ans = min(ans, abs((total - i) - i));
//             }
//         }
//         return ans;
        
        
//         // This is accepted in both cases of half of sum and full of sum
        
//         // if(nums[0] <= sum)
//         //     dp[0][nums[0]] = 1;
//         // for(int i = 0; i < n; i++)
//         // {
//         //     dp[i][0] = 1;
//         // }
        
//         // for(int i = 1; i < n; i++)
//         // {
//         //     for(int j = 1; j <= sum; j++)
//         //     {
//         //         dp[i][j] |= dp[i-1][j];
//         //         if(j - nums[i] >= 0)
//         //             dp[i][j] |= dp[i-1][j-nums[i]];
//         //     }
//         // }
        
        
        
//         // for(int i = 0; i <= n; i++)
//         // {
//         //     for(int j = 0; j <= sum; j++)
//         //         cout << dp[i][j] << " ";
//         //     cout << endl;
//         // }
        
//         // int ans = total;
//         // for(int i = 0; i <= sum; i++)
//         // {
//         //     if(dp[n-1][i])
//         //     {
//         //         // cout << i << endl;
//         //         ans = min(ans, abs((total - i) - i));
//         //     }
//         // }
//         // return ans;
// 	} 
// };


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