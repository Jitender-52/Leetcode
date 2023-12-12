class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mini1 = 1e4, mini2 = 1e4, maxi1 = -1e4, maxi2 = -1e4;
        for(int i = 0; i < n; i++)
        {
            nums[i]--;
            if(nums[i] <= mini1)
            {
                mini2 = mini1;
                mini1 = nums[i];
            }
            else
            {
                mini2 = min(mini2, nums[i]);
            }
            
            if(nums[i] >= maxi1)
            {
                maxi2 = maxi1;
                maxi1 = nums[i];
            }
            else
            {
                maxi2 = max(maxi2, nums[i]);
            }
        }
        return max(mini1 * mini2, maxi1 * maxi2);
    }
};