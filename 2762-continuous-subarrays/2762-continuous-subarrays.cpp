class Solution {
public:
    
//     Runtime: 100 ms, faster than 71.86% of C++ online submissions for Continuous Subarrays.
// Memory Usage: 112.8 MB, less than 87.68% of C++ online submissions for Continuous Subarrays.
    
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        // map<int, set<int>> mp;
        // map<int, vector<int>> mp;
        map<long long,long long> mp;
        long long j = 0;
        long long ans = 0;
        for(long long i = 0; i < n; i++)
        {
            // mp[nums[i]].push_back(i);
            mp[nums[i]]++;
            // if(i == 3)
            // {
            //     for(auto i : mp)
            //     {
            //         cout << i.first <<" ";
            //     }
            //     cout << endl;
            //     cout << "Check = " << mp.begin()->first << " " << mp.rbegin()->first << endl;
            // }
            while(j < i && (abs(mp.begin()->first - nums[i]) > 2 || abs(mp.rbegin()->first - nums[i]) > 2))
            {
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                {
                    mp.erase(nums[j]);
                }
                j++;
            }
            // cout << i << " " << j << endl;
            ans += 0LL + i - j + 1;
            // cout << ans << endl;
        }
        return ans;
    }
};