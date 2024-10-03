class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = 0;
        for(auto i : nums)
            sum += i;
        int x = sum % p;
        if(x == 0)
            return x;
        map<int,int> mp;
        mp[0] = -1;
        sum = 0;
        int ans = n;
        for(int i = 0; i < n; i++)
        {
            (sum += nums[i]) %= p;
            int y = (sum + p - x) % p;
            if(mp.find(y) != mp.end())
                ans = min(ans, i - mp[y]);
            mp[sum] = i;
        }
        if(ans == n)
            return -1;
        return ans;
    }
};