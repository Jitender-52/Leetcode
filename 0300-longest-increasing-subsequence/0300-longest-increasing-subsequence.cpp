class Solution {
public:
    
//     Runtime: 10 ms, faster than 82.11% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage: 10.9 MB, less than 46.64% of C++ online submissions for Longest Increasing Subsequence.
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            if(idx >= v.size())
                v.push_back(nums[i]);
            else
                v[idx] = nums[i];
            
        }
        return v.size();
    }
};