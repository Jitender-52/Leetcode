class Solution {
public:
    
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        pq.push({nums[0], 0});
        int ans = nums[0];
        
        for(int i = 1; i < n; i++)
        {
            while(i - pq.top().second > k)
            {
                pq.pop();
            }
            
            int count = max(0, pq.top().first) + nums[i];
            ans = max(ans, count);
            pq.push({count, i});
        }
        return ans;
    }
};
    
    
//     int solve(int i, int k, vector<int> &nums, vector<int> &dp)
//     {
//         int n = nums.size();
//         if(i >= n)
//             return 0;
//         if(dp[i] != INT_MIN) // my bad used -1 here which can be the value
//             return dp[i];
//         int ans = nums[i];
//         int count = 0;
//         for(int j = 1; j <= k; j++)
//         {
//             if(i + j >= n)
//                 break;
//             count = max(count, solve(i+j, k, nums, dp));
//         }
//         return dp[i] = ans + count;
//     }
    
//     int constrainedSubsetSum(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> dp(n, INT_MIN);
//         int ans = INT_MIN;
//         for(int i = 0; i < n; i++)
//         {
//             ans = max(ans, solve(i, k, nums, dp));
//         }
//         return ans;
//     }
// };