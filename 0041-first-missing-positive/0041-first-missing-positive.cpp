class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int n = nums.size();
        map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= 1 && nums[i] <= 1e5)
                mp[nums[i]] = 1;
        }
        for(int i = 1; i <= 1e5+1; i++)
        {
            if(mp.find(i) == mp.end())
                return i;
        }
        return -1;
    }
};