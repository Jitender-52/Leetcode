class Solution {
public:
    
        bool isFeasible(vector<int> &nums, int k, int maxi)
        {
            int n = nums.size();
            int count = 0;
            
            for(int i = 0; i < n; i++)
            {
                if(nums[i] <= maxi)
                {
                    count++;
                    i++;
                }
            }
            
            if(count >= k)
                return true;
            return false;
            
        }
    
        int minCapability(vector<int>& nums, int k) {
            int n = nums.size();
            
            int maxi = 0;
            
            for(int i = 0; i < n; i++)
            {
                maxi = max(maxi, nums[i]);
            }
            
            int low = 0;
            
            int high = maxi;
            
            int ans = INT_MAX;
            
            while(low <= high)
            {
                int mid = (low + high) / 2;
                if(isFeasible(nums, k, mid))
                {
                    ans = min(ans, mid);
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            
            return ans;
            
        }
};
    
    
    
    
//     int find(int i, vector<int> &nums, int k, vector<vector<int>> &dp)
//     {
//         int n = nums.size();
        
//         if(k == 0)
//             return 0;
        
//         if(i >= n)
//             return INT_MAX;
        
//         if(dp[i][k] != -1)
//             return dp[i][k];
        
//         int ans = INT_MAX;
        
// //         for(int j = k; j < dp[i].size(); j++)
// //         {
// //             if(dp[i][j] != -1)
// //                 ans = min(ans, dp[i][j]);
// //                 // return dp[i][j];
// //         }
        
// //         if(ans != INT_MAX)
// //             return ans;
        
        
        
//         ans = min(max(nums[i], find(i+2, nums, k-1, dp)), find(i+1, nums, k, dp));
//         return dp[i][k] = ans;
//     }
    
//     int minCapability(vector<int>& nums, int k) {
//         int n = nums.size();
        
//         // vector<bool> vis(n + 2, 0);
        
        
//         // vector<int> dp(n+1, -1);
        
//         // vector<vector<int>> dp(n, vector<int>(k+1, -1));
//         //         return find(0, nums, k, dp);
        
//         vector<vector<int>> dp(n+2, vector<int>(k+2, INT_MAX));

        
//         for(int i = 0; i <= n; i++)
//         {
//             dp[i][0] = 0;
//         }
        
//         // for(int j = 0;j <= k; j++)
//         // {
//         //     dp[0][j] = INT_MAX;
//         // }
        
//         for(int i = 1; i <= n; i++)
//         {
//             for(int j = 1; j <= k; j++)
//             {
//                 // if(i >= 2)
//                 dp[i][j] = min(max(dp[i-2][j-1], nums[i-1]), dp[i-1][j]);
//                 // else
//                 //     dp[i][j] = min()
//             }
//         }
        
// // 2147483647 2147483647 2147483647 
// // 0 2147483647 2147483647 
// // 0 7 2147483647 
// // 0 7 9 
// // 0 3 7 
// // 0 1 3 

        
//         for(int i = 0; i <= n; i++)
//         {
//             for(int j = 0; j <= k; j++)
//             {
//                 cout << dp[i][j] << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
        
//         int ans = INT_MAX;
//         for(int i = 0; i <= n; i++)
//         {
//             ans = min(ans, dp[i][k]);
//         }
        
//         return ans;
        
//         // return find(0, nums, k, dp);
        
// //         vector<pair<int,int>> v;
// //         for(int i = 0; i < n; i++)
// //         {
// //             v.push_back({nums[i], i});
// //         }
        
        
        
// //         sort(v.begin(), v.end());
        
// //         int ans = INT_MAX;
// //         for(int i = 0; i < n && k > 0; i++)
// //         {
// //             int a = v[i].first;
// //             int b = v[i].second;
            
// //             if(vis[b-1] || vis[b+1])
// //             {
// //                 continue;
// //             }
// //             else
// //             {
// //                 ans = max(ans, )
// //                 k--;
// //             }
// //         }
//     }
// };