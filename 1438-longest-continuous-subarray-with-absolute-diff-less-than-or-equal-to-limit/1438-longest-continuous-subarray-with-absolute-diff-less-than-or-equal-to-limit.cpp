class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        map<int,int> mp;
        int ans = 0;
        int count = 0;
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
            while(mp.rbegin()->first - mp.begin()->first > limit)
            {
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                {
                    mp.erase(nums[j]);
                }
                j++;
            }    
            // cout << mp.rbegin()->first << " " << mp.begin()->first << endl;
            ans = max(ans, i - j + 1);
        }
        j = n-1;
        mp.clear();
        for(int i = n-1; i >= 0; i--)
        {
            mp[nums[i]]++;
            while(mp.rbegin()->first - mp.begin()->first > limit)
            {
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                {
                    mp.erase(nums[j]);
                }
                j--;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};