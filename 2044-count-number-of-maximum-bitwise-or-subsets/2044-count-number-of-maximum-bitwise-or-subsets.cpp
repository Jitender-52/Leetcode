class Solution {
public:
    
//     Runtime: 150 ms, faster than 11.74% of C++ online submissions for Count Number of Maximum Bitwise-OR Subsets.
// Memory Usage: 10 MB, less than 93.24% of C++ online submissions for Count Number of Maximum Bitwise-OR Subsets.
    
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