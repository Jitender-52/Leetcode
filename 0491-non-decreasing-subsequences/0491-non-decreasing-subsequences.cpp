class Solution {
public:
    
//     Runtime: 667 ms, faster than 5.09% of C++ online submissions for Non-decreasing Subsequences.
// Memory Usage: 102.4 MB, less than 8.21% of C++ online submissions for Non-decreasing Subsequences.
    
    
    
    
    void find(int i, vector<int> &nums, vector<int> v, map<vector<int>, int> &mp)
    {
        int n = nums.size();
        if(v.size() > 1)
        {
            mp[v]++;
        }
        if(i >= n)
            return;
        
        // find(i + 1, nums, v, mp);
        
//         if(nums[i] >= v[v.size()-1])
//             v.push_back(nums[i]);
        
//         find(i+1, nums, v, mp);
        
        for(int  j = i; j < n; j++)
        {
            if(nums[j] >= v[v.size() - 1])
            {
                v.push_back(nums[j]);
                find(j+1, nums, v, mp);
                v.pop_back();
            }
        }
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