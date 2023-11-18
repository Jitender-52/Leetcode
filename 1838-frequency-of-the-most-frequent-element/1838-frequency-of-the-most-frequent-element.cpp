class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long i = 0, j = 0;
        long long sum = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            while(j < n && (nums[j] * 1LL * (j - i + 1)) - (sum + nums[j]) <= k)
            {
                sum += nums[j];
                j++;
            }
            ans = max(ans, j - i);
            sum -= nums[i];
        }
        return ans;
    }
};