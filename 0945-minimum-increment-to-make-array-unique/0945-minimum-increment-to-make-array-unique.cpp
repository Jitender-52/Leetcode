class Solution {
public:
    
//     Runtime: 117 ms, faster than 68.70% of C++ online submissions for Minimum Increment to Make Array Unique.
// Memory Usage: 69.1 MB, less than 50.39% of C++ online submissions for Minimum Increment to Make Array Unique.

    
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] <= nums[i-1])
            {
                ans += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        return ans;
    }
};