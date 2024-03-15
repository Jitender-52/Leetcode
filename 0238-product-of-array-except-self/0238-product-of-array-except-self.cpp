class Solution {
public:
    
//     Runtime: 16 ms, faster than 59.62% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 27.5 MB, less than 13.83% of C++ online submissions for Product of Array Except Self.
    
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix = nums, suffix = nums;
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] * nums[i];
        for(int i = n-2; i >= 0; i--)
            suffix[i] = suffix[i+1] * nums[i];
        vector<int> ans(n);
        ans[0] = suffix[1];
        ans[n-1] = prefix[n-2];
        for(int i = 1; i < n-1; i++)
            ans[i] = prefix[i-1] * suffix[i+1];
        return ans;
    }
};