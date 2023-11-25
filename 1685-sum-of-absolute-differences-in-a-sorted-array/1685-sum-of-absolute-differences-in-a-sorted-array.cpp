class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += nums[i];
        vector<int> ans(n);
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            ans[i] = (i * nums[i] - count) + (sum - count -  nums[i] * (n - i));
            count += nums[i];
        }
        return ans;
    }
};