class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> v(n, 0);
        for(int i = 0; i < n; i++)
            v[i] = i;
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    v[i] = j;
                } 
            }
        }
        int maxi = 0;
        for(int i = 0; i < n; i++)
            maxi = max(maxi, dp[i]);
        int idx = 0;
        for(int i = 0; i < n; i++)
        {
            if(dp[i] == maxi)
            {
                idx = i;
                break;
            }
        }
        vector<int> ans;
        while(v[idx] != idx)
        {
            ans.push_back(nums[idx]);
            idx = v[idx];
        }
        ans.push_back(nums[idx]);
        sort(ans.begin(), ans.end());
        return ans;
    }
};