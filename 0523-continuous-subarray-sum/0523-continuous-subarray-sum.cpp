class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            sum %= k;
            if(mp.find(sum) != mp.end() && ((i + 1 - mp[sum]) >= 2))
                 return true;
            if(i >= 1 && sum == 0)
                return true;
            if(mp.find(sum) == mp.end())
                mp[sum] = i+1;
        }
        return false;
    }
};
