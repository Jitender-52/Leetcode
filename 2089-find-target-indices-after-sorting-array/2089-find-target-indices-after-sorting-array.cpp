class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            while(i < n && nums[i] == target)
                ans.push_back(i++);
        }
        return ans;
    }
};