class Solution {
public:
    
//     Runtime: 63 ms, faster than 80.35% of C++ online submissions for Minimum Swaps to Group All 1's Together II.
// Memory Usage: 83.1 MB, less than 57.56% of C++ online submissions for Minimum Swaps to Group All 1's Together II.
    
    int minSwaps(vector<int>& nums) {
        int s = nums.size();
        int ones = 0;
        for (int n : nums)
            ones += n;
        if (ones == 0 || ones == s) 
            return 0;
        int curr = 0;
        for (int i = 0; i < ones; i++) 
            curr += nums[i];
        int maxi = curr;
        for (int i = 0; i < s; i++) 
        {
            curr -= nums[i];
            curr += nums[(i + ones) % s];
            maxi = max(maxi, curr);
        }
        return ones - maxi;
    }
};