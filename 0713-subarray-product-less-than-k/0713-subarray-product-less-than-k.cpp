class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, x = 1, ans = 0;
        
        if(k <= 1)
            return 0;
        
        while(j < n)
        {
            if(x < k)
            {
                if(i == n)
                    break;
                x *= nums[i];
                i++;
            }
            else
            {
                x /= nums[j];
                j++;
            }
            // cout << i << " " << x << " " << k << endl;
            if(x < k)
            {
                // cout << i << " " << j << " " << x << " " << k << endl;
                ans += i - j;
            }
        }
        return ans;
    }
};