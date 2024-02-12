class Solution {
public:
    
//     Runtime: 17 ms, faster than 35.13% of C++ online submissions for Majority Element.
// Memory Usage: 22.2 MB, less than 18.20% of C++ online submissions for Majority Element.
    
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