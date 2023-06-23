class Solution {
public:
    
        int longestArithSeqLength(vector<int>& nums) {
            int n = nums.size();
            int ans = 0;
            unordered_map<int, unordered_map<int,int>> dp;
            
            for(int i = 0; i < n; i++)
            {
                for(int j = i+1; j < n; j++)
                {
                    int diff = nums[j] - nums[i];
                    dp[diff][j] = dp[diff].count(i) ? dp[diff][i]+1 : 2;
                    ans = max(ans, dp[diff][j]);
                }
            }
            return ans;
        }
};
    
        
//     int longest(int i, int last, int diff, vector<int> &nums, vector<vector<int>> &dp)
//     {
//         int n = nums.size();
//         if(i >= n)
//             return 0;
//         // if(dp[i][diff] != -1)
//         //     return dp[i][diff];
//         if(last + diff == nums[i])
//             return dp[i][diff] = 1 + longest(i+1, nums[i], diff, nums, dp);
//         else
//             return dp[i][diff] = longest(i+1, last, diff, nums, dp);
//     }
    
//     int longestArithSeqLength(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int> (501, -1));
//         int ans = 0;
//         int maxi = *max_element(nums.begin(), nums.end());
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < 501; j++)
//             {
//                 ans = max(ans, 1 + longest(i+1, nums[i], j, nums, dp));
//             }
//         }
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < 501; j++)
//             {
//                 dp[i][j] = -1;
//             }
//         }
        
//         reverse(nums.begin(), nums.end());
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j <= maxi; j++)
//             {
//                 ans = max(ans, 1 + longest(i+1, nums[i], j, nums, dp));
//             }
//         }
                
//         return ans;
//     }
// };
    
    
//     int longestArithSeqLength(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> v(501, 0);
//         for(int i = 0; i < n; i++)
//         {
//             v[nums[i]]++;
//         }
        
//         int ans = 0;
//         for(auto it : nums)
//         {
//             if(it == 0)
//             {
//                 ans = max(ans, v[it]);
//                 continue;
//             }
//             for(int i = 0; i <= 500; i++)
//             {
//                 if(i == 0)
//                 {
//                     ans = max(ans, v[it]);
//                     continue;
//                 }
//                 int x = it, count = 0;
//                 while(x < 501 && v[x] > 0)
//                 {
//                     count++;
//                     x += i;
//                 }
//                 if(count == 5)
//                 {
//                     cout << it << " " << i << endl;
//                 }
//                 ans = max(ans, count);
//             }
//         }        
//         return ans;
//     }
// };