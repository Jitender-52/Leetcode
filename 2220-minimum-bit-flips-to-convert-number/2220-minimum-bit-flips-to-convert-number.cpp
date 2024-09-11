class Solution {
public:

//         Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Bit Flips to Convert Number.
// Memory Usage: 7.6 MB, less than 44.87% of C++ online submissions for Minimum Bit Flips to Convert Number.
    
    int minBitFlips(int start, int goal) {
        int ans = 0;
        for(int i = 0; i < 31; i++)
        {
            bool a = start & (1 << i), b = goal & (1 << i);
            // cout << a << " " << b << endl;
            ans += (a ^ b);
        }
        return ans;
    }
};