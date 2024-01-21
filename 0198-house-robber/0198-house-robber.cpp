class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n >= 3)
            nums[2] += nums[0];
        for(int i = 3; i < n; i++)
        {
            nums[i] += max(nums[i-3], nums[i-2]);
        }
        return max(nums[n-2], nums[n-1]);
    }
};