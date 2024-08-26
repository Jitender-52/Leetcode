class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        for(int i = 0; i < k; i++)
        {
            int mini = 1e9;
            for(int j = 0; j < n; j++)
                mini = min(mini, nums[j]);
            for(int j = 0; j < n; j++)
            {
                if(nums[j] == mini)
                {
                    nums[j] *= multiplier;
                    break;
                }
            }
        }
        return nums;
    }
};