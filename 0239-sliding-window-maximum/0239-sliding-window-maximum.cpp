class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        int j = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
            if(i - j + 1 > k)
            {
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }
            if(i - j + 1 == k)
                ans.push_back(mp.rbegin()->first);
        }
        return ans;
    }
};