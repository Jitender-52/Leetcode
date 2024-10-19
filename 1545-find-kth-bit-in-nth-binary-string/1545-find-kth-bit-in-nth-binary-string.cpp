class Solution {
public:
    
//     Runtime: 86 ms, faster than 16.04% of C++ online submissions for Find Kth Bit in Nth Binary String.
// Memory Usage: 57.2 MB, less than 45.56% of C++ online submissions for Find Kth Bit in Nth Binary String.
    
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 1; i < n; i++)
        {
            string p = s;
            reverse(p.begin(), p.end());
            s += '1';
            for(auto i : p)
            {
                if(i == '0')
                    s += '1';
                else
                    s += '0';
            }
        }
        return s[k-1];
    }
};