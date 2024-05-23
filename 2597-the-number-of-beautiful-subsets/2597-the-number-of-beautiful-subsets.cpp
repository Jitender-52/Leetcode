class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        vector<int> v(1002, 0);
        for(int i = 1; i < (1 << n); i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i & (1 << j))
                {
                    v[nums[j]] = 1;
                }
            }
            bool check = true;
            for(int j = 0; j < n; j++)
            {
                if((i & (1 << j)) && nums[j] - k > 0 && v[nums[j] - k] == 1)
                {
                    check = false;
                    break;
                }
            }
            if(check)
                ans++;
            for(int j = 0; j < n; j++)
            {
                v[nums[j]] = 0;
            }
        }
        return ans;
    }
};

        