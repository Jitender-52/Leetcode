class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= n; i++)
        {
            auto count = nums.end() - lower_bound(nums.begin(), nums.end(), i);
            if(count == i)
                return i;
        }
        return -1;
    }
};