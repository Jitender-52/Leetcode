class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        map<int,int> mp;
        int sum = 0, ans = 0;
        mp[0] = 1;
        for(auto i : nums)
        {
            sum += i;
            if(mp.find(sum - goal) != mp.end())
                ans += mp[sum - goal];
            mp[sum]++;
        }
        return ans;
    }
};
// 1 1 2 2 3