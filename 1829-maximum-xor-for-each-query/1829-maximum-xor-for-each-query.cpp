class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum XOR for Each Query.
// Memory Usage: 98.3 MB, less than 43.73% of C++ online submissions for Maximum XOR for Each Query.
    
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> prefixXOR(n);
        prefixXOR[0] = nums[0];

        for (int i = 1; i < n; i++) 
            prefixXOR[i] = prefixXOR[i - 1] ^ nums[i];

        vector<int> ans(n);
        int mask = (1 << maximumBit) - 1;

        for (int i = 0; i < n; i++) 
        {
            int currentXOR = prefixXOR[n - 1 - i];
            ans[i] = currentXOR ^ mask;
        }
        return ans;
    }
};