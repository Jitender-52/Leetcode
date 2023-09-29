class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool check1 = 1, check2 = 1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] > nums[i-1])
                check1 &= 0;
            if(nums[i] < nums[i-1])
                check2 &= 0;
        }
        return check1 | check2;
    }
};