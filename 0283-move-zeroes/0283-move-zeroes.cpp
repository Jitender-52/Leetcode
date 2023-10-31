class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while(i < n)
        {
            while(i < n && nums[i] == 0)
                i++;
            while(j < i && nums[j] != 0)
                j++;
            if(i < n)
                swap(nums[i], nums[j]);
            i++;
        }
    }
};