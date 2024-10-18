class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i = 0; i < (1 << n); i++)
        {
            int x = 0;
            for(int j = 0; j  < n; j++)
            {
                if(i & (1 << j))
                    x |= nums[j];
            }
            maxi = max(maxi, x);
        }
        int ans = 0;
        for(int i = 0; i < (1 << n); i++)
        {
            int x = 0;
            for(int j = 0; j  < n; j++)
            {
                if(i & (1 << j))
                    x |= nums[j];
            }
            ans += x == maxi;
        }
        return ans;
    }
};