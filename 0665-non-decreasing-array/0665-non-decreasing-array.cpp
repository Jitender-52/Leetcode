class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool check = false;
        for(int i = 1; i < n; i++)
        {
            if(nums[i-1] > nums[i])
            {
                if(check)
                    return false;
                check = true;
                if(i - 2 < 0 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
            }
        }
        return true;
    }
};