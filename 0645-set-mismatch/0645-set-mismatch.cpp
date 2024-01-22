class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1)
                ans.push_back(nums[i]);
        }
        
        for(int i = 1; i <= n; i++)
        {
            if(mp[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};