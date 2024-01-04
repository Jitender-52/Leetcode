class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(auto i : nums)
            mp[i]++;
        int ans = 0;
        for(auto i : mp)
        {
            if(i.second == 1)
                return -1;
            ans += i.second / 3;
            ans += (i.second % 3) != 0;
        }
        return ans;
    }
};