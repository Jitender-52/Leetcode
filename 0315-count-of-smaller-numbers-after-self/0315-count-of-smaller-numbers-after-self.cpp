class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        sort(v.begin(), v.end());
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++)
        {
            auto it = lower_bound(v.begin(), v.end(), nums[i]);
            v.erase(it);
            ans[i] = it - v.begin();
        }
        return ans;
    }
};