class Solution {
public:
    
//     Runtime: 169 ms, faster than 44.86% of C++ online submissions for Divide Array Into Arrays With Max Difference.
// Memory Usage: 115.4 MB, less than 61.98% of C++ online submissions for Divide Array Into Arrays With Max Difference.
    
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> v;
        v.push_back(nums[0]);
        for(int i = 1; i < n; i++)
        {
            v.push_back(nums[i]);
            if(i % 3 == 2)
            {
                if(v[2] - v[0] > k)
                    return {};
                ans.push_back(v);
                v = {};
            }
        }
        return ans;
    }
};