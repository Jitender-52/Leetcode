class Solution {
public:
    
//     Runtime: 98 ms, faster than 35.41% of C++ online submissions for Sum of Absolute Differences in a Sorted Array.
// Memory Usage: 83.8 MB, less than 60.81% of C++ online submissions for Sum of Absolute Differences in a Sorted Array.

    
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