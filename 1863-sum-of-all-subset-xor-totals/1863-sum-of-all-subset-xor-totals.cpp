class Solution {
public:
    
//     Runtime: 3 ms, faster than 68.97% of C++ online submissions for Sum of All Subset XOR Totals.
// Memory Usage: 8.3 MB, less than 88.36% of C++ online submissions for Sum of All Subset XOR Totals.
    
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