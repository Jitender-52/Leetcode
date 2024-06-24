class Solution {
public:
    
//     Runtime: 90 ms, faster than 61.07% of C++ online submissions for Minimum Number of K Consecutive Bit Flips.
// Memory Usage: 113.3 MB, less than 10.25% of C++ online submissions for Minimum Number of K Consecutive Bit Flips.

    
    int minKBitFlips(vector<int> &nums, int k){
        vector<int> v(nums.size(), false);
        int count = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i >= k && v[i - k])
            {
                count--;
            }
            if (count % 2 == nums[i])
            {
                if (i + k > nums.size())
                    return -1;
                count++;
                v[i] = true;
                ans++;
            }
        }
        return ans;
    }
};