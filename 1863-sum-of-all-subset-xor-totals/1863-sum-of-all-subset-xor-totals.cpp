class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x = 0; x < (1 << n); x++)
        {
            int a = 0;
            for(int i = 0; i < n; i++)
            {
                if(x & (1 << i))
                    a ^= nums[i];
            }
            sum += a;
        }
        return sum;
    }
};