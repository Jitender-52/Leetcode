class Solution {
public:
    
     int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
        vector<int> v(n+1, -1e5);
        for(int i = 0; i < n; i++)
            v[i+1] = nums[i];
         
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
        
        for(int i = n; i >= 1; i--)
        {
            for(int j = 0; j < i; j++)
            {
                if(v[i] > v[j])
                    dp[i][j] = max(1 + dp[i+1][i], dp[i][j]);
                dp[i][j] = max(dp[i][j], dp[i+1][j]);
            }
        }
         
        // for(int i = 0; i <= n; i++)
        // {
        //     for(int j = 0; j <= n; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[1][0];
     }
};
    

// It will not work because it needs 1 smallest number at the front which can store their maximum as in recurive method to know the differnce run the below and above both code and print the 2D dp's to know the difference
    
//      int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
//         for(int i = n-1; i >= 0; i--)
//         {
//             for(int j = 0; j < i; j++)
//             {
//                 if(nums[i] > nums[j])
//                     dp[i][j] = max(dp[i][j], 1 + dp[i+1][i]);
//                 dp[i][j] = max(dp[i][j], dp[i+1][j]);
//             }
//         }
//         for(int i = 0; i <= n; i++)
//         {
//             for(int j = 0; j <= n; j++)
//             {
//                 cout << dp[i][j] << " ";
//             }
//             cout << endl;
//         }
//         return dp[0][0];
//     }
// };
    
//     Runtime: 1332 ms, faster than 19.64% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage: 292.6 MB, less than 8.42% of C++ online submissions for Longest Increasing Subsequence.
    
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
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
//         vector<int> v(n+1);
//         v[0] = -1e4;
//         for(int i = 0; i < n; i++)
//             v[i+1] = nums[i];
//         return longest(1, 0, v, dp); 
//     }
// };