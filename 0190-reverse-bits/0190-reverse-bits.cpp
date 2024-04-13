class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Bits.
// Memory Usage: 7.2 MB, less than 7.24% of C++ online submissions for Reverse Bits.

    uint32_t reverseBits(uint32_t n) {
        long long ans = 0;
        for(int i = 0; i < 32; i++)
        {
            if((n & (1LL << i))) 
                ans += 1LL << (31-i);
        }
        return ans;
    }
};