class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    int ans;
    int maxi = 0;
    for (auto it : mp)
    {
        int a = it.second;
        if (a > maxi)
        {
            maxi = a;
            ans = it.first;
        }
    }
    return ans;
    }
};