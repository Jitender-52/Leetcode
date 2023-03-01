class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        int j = 0;
        for(auto i : mp)
        {
            for(auto k = 0; k < i.second; k++)
            {
                nums[j] = i.first;
                j++;
            }
        }
        return nums;
    }
};