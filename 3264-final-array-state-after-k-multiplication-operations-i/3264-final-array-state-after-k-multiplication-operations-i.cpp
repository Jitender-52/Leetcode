class Solution {
public:
    
//     Runtime: 13 ms, faster than 30.00% of C++ online submissions for Final Array State After K Multiplication Operations I.
// Memory Usage: 26.2 MB, less than 80.00% of C++ online submissions for Final Array State After K Multiplication Operations I.
    
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