class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        int maxi = 0;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
            maxi = max(maxi, mp[nums[i]]);
        }
        vector<vector<int>> ans(maxi);
        for(auto i : mp)
        {
            for(int j = 0; j < i.second; j++)
                ans[j].push_back(i.first);
        }
        return ans;
    }
};