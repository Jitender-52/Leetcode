class Solution {
public:
    
//     Runtime: 274 ms, faster than 17.50% of C++ online submissions for Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit.
// Memory Usage: 77.8 MB, less than 33.75% of C++ online submissions for Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit.
    
    
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
        // j = n-1;
        // mp.clear();
        // for(int i = n-1; i >= 0; i--)
        // {
        //     mp[nums[i]]++;
        //     while(mp.rbegin()->first - mp.begin()->first > limit)
        //     {
        //         mp[nums[j]]--;
        //         if(mp[nums[j]] == 0)
        //         {
        //             mp.erase(nums[j]);
        //         }
        //         j--;
        //     }
        //     ans = max(ans, j - i + 1);
        // }
        return ans;
    }
};