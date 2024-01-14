class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        for(auto i : nums)
        {
            mp[i]++;
        }
        int maxi = 0;
        for(auto i : mp)
        {
            maxi = max(maxi, i.second);
        }
        int ans = 0;
        for(auto i : mp)
        {
            if(i.second == maxi)
                ans += i.second;
        }
        return ans;
    }
};