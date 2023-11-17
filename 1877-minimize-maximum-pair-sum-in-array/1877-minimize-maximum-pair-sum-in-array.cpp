class Solution {
public:
    
//     Runtime: 192 ms, faster than 40.57% of C++ online submissions for Minimize Maximum Pair Sum in Array.
// Memory Usage: 96.5 MB, less than 61.58% of C++ online submissions for Minimize Maximum Pair Sum in Array.

    
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < n/2; i++)
        {
            ans = max(ans, nums[i] + nums[n-i-1]);   
        }
        return ans;
    }
};