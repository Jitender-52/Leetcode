class Solution {
public:
    
    int maxLines(int i, int j, int maxi, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        // cout << i << " " << j << endl;
        int n = nums1.size();
        int m = nums2.size();
        if(i >= n || j >= m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        // if(nums1[i] < maxi)
        //     return dp[i][j] = maxLines(i+1, j, maxi, nums1, nums2, dp);
        // if(nums2[j] < maxi)
        //     return dp[i][j] = maxLines(i+1, j, maxi, nums1, nums2, dp);
        
        int ans = 0;
        if(nums1[i] == nums2[j])
            ans = max(ans, 1 + maxLines(i+1, j+1, nums1[i], nums1, nums2, dp));
        ans = max(ans, max(maxLines(i+1, j, maxi, nums1, nums2, dp), maxLines(i, j+1, maxi, nums1, nums2, dp)));
        
         return dp[i][j] = ans;
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return maxLines(0, 0, 0, nums1, nums2, dp);
    }
};