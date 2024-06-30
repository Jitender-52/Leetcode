class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int odd = 0, even = 0;
        int ans = 0, count = 0;
        int totalOdd = 0, totalEven = 0;
        for(int i = 0; i < n; i++) // Taking odd sum;
        {
            totalOdd += nums[i] % 2;
            totalEven += !(nums[i] % 2);
        }
        ans = max(totalOdd, totalEven);
        ans = max(ans, count);
            
        int a = 1, count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == a)
            {
                count1++;
                a ^= 1;
            }
        }
        a = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == a)
            {
                count2++;
                a ^= 1;
            }
        }
        ans = max(ans, max(count1, count2));
        return ans;
    }
};