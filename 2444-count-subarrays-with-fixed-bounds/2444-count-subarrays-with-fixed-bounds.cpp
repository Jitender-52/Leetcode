class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int mini = -1, maxi = -1, index = -1;
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < minK || nums[i] > maxK)
                index = i;
            if(nums[i] == minK)
                mini = i;
            if(nums[i] == maxK)
                maxi = i;
            ans += max(0, min(mini, maxi) - index);
        }
        return ans;
    }
};