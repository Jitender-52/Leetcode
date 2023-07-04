class Solution {
public:
    
//     Runtime: 15 ms, faster than 16.54% of C++ online submissions for Single Number II.
// Memory Usage: 10 MB, less than 20.94% of C++ online submissions for Single Number II.
// Next challenges:
    
    int singleNumber(vector<int>& nums) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for(auto i : mp)
        {
            if(i.second == 1)
            {
                return i.first;
            }
        }
        return nums[0];
    }
};