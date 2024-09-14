class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi  = 0;
        for(int i = 0; i  < n; i++)
        {
            maxi = max(maxi, nums[i]);
        }
        int count = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == maxi)
               count++;
            else
            {
                count = 0;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};

// [311155,311155,311155,311155,311155,311155,311155,311155,201191,311155]