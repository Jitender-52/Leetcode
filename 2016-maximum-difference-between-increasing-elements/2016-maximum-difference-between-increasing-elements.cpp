class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, nums[i] - mini);
            mini = min(mini, nums[i]);
        }
        if(ans == 0)
            return -1;
        return ans;
    }
};