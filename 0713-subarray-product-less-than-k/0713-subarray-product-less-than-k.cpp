class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        long long product = 1;
        int i = 0;
        int j = 0;
        while(i <= n && j < n)
        {
            if(product < k)
            {
                if(i == n)
                    break;
                product *= nums[i];
                i++;
            }
            else
            {
                product /= nums[j];
                j++;
            }
            if(product < k)
            {
                ans += i - j;
            }
        }
        return ans;
    }
};