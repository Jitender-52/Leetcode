class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 0), suff(n, 0);
        
        if(nums[0] == 1)
            pref[0] = 1;
        if(nums[n-1] == 1)
            suff[n-1] = 1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == 1)
                pref[i] = pref[i-1] + 1;
        }
        for(int i = n-2; i >= 0; i--)
        {
            if(nums[i] == 1)
                suff[i] = suff[i+1] + 1;
        }
        
        int ans = max(pref[n-2], suff[1]); // base condition which I forget, it will be used because i = 1 to n-1. So these two points will left.
        for(int i = 1; i < n - 1; i++) 
        {
            ans = max(ans, pref[i-1] + suff[i+1]);
        }
        return ans;
    }
};