class Solution {
public:
    
    void find(int i, vector<int> &nums, vector<int> v, map<vector<int>, int> &mp)
    {
        int n = nums.size();
        if(v.size() > 1)
        {
            mp[v]++;
        }
        if(i >= n)
            return;
        
        find(i + 1, nums, v, mp);
        
        if(nums[i] >= v[v.size()-1])
            v.push_back(nums[i]);
        
        find(i+1, nums, v, mp);
        
        // for(int  j = i; j < n; j++)
        // {
        //     find(j+1, nums, v, mp);
        // }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        map<vector<int>, int> mp;
        for(int i = 0; i < n; i++)
        {
            vector<int> v;
            v.push_back(nums[i]);
            find(i+1, nums, v, mp);
        }
        
        vector<vector<int>> ans;
        for(auto i : mp)
        {
            ans.push_back(i.first);
        }
        return ans;
    }
};