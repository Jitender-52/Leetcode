class Solution {
public:
    
    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        int n = nums1.size(), m = nums2.size();
        if(i >= n || j >= m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = max(max(0, nums1[i] * nums2[j]) + solve(i+1, j+1, nums1, nums2, dp), max(solve(i+1, j, nums1, nums2, dp), solve(i, j+1, nums1, nums2, dp)));
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int fmax = *max_element(nums1.begin(), nums1.end());
        int fmin = *min_element(nums1.begin(), nums1.end());
        int smax = *max_element(nums2.begin(), nums2.end());
        int smin = *min_element(nums2.begin(), nums2.end());
        
        if(fmax < 0 && smin > 0)
            return fmax * smin;
        if(smax < 0 && fmin > 0)
            return smax * fmin;
        
        int n = nums1.size(), m =  nums2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        
        return solve(0, 0, nums1, nums2, dp);
        
        // for(int i = n-1; i >= 0; i--)
        // {
        //     for(int j = m-1; j >= 0; j--)
        //     {
        //         dp[i][j] = max(dp[i+1][j+1], dp[i])
        //     }
        // }
        
    }
};