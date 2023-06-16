class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(32);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 31; j++)
            {
                // cout << nums[i] << " " << (1 << j) << endl;
                if((nums[i] & (1 << j)))
                {
                    // cout << nums[i] << " " << (i >> j) << endl;
                    v[j]++;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            ans += v[i] * (n - v[i]);
        }
        return ans;
    }
};