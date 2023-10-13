class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(k - nums[i]) != mp.end())
            {
                mp[k - nums[i]]--;
                if(mp[k-nums[i]] == 0)
                    mp.erase(k - nums[i]);
                ans++;
            }
            else
            {
                mp[nums[i]]++;
            }
        }
        return ans;
    }
};