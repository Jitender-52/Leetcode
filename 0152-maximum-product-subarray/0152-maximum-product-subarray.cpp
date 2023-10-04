class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(2, 1);
        int ans = -1e9;
        for(int i = n-1; i >= 0; i--)
        {
            vector<int> curr(2, nums[i]);
            int a = prev[0] * nums[i];
            int b = prev[1] * nums[i];
            curr[0] = min(curr[0], min(a, b));
            curr[1] = max(curr[1], max(a, b));
            ans = max({ans, curr[0], curr[1]});
            prev = curr;
        }
        return ans;
    }
};
    
    
//     Runtime: 15 ms, faster than 5.66% of C++ online submissions for Maximum Product Subarray.
// Memory Usage: 17 MB, less than 6.97% of C++ online submissions for Maximum Product Subarray.
    
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int> (2, 1));
        
//         int ans = INT_MIN;
//         for(int i = n-1; i >= 0; i--)
//         {
//             int a = dp[i+1][0] * nums[i];
//             int b = dp[i+1][1] * nums[i];
//             dp[i][0] = min(nums[i], min(a, b));
//             dp[i][1] = max(nums[i], max(a, b));
//             ans = max(ans, max(dp[i][0], dp[i][1]));
//         }
//         return ans;
//     }
// };