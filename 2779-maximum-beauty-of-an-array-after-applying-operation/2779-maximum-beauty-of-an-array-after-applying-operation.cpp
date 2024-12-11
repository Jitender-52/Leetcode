class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i < n)
        {
            if(nums[i] - nums[j] <= 2 * k)
            {
                ans = max(ans, i - j + 1);
                i++;
            }
            else if(i == j)
                i++;
            else
                j++;
        }
        return ans;
    }
};