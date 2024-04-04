class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;
        int ans = n+1;
        for(int i = 0; i < n; i++)
        {
            int a = 0;
            for(int j = i; j < n; j++)
            {
                a |= nums[j];
                if(a >= k)
                {
                    ans = min(ans, j-i+1);
                    break;
                }
            }
        }
        return ans == n+1 ? -1 : ans;
    }
};