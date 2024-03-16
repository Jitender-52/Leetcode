class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        mp[0] = -1;
        int count = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(!nums[i])
                count++;
            else
                count--;
            if(mp.find(count) != mp.end())
                ans = max(ans, i - mp[count]);
            else
                mp[count] = i;
        }
        return ans;
    }
};