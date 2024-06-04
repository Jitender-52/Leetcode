class Solution {
public:
    bool hasAlternatingBits(int n) {
        int a = ((n & (1 << 0)) != 0);
        int m = log2(n);
        for(int i = 0; i <= m; i++)
        {
            if(((n & (1 << i)) != 0) != a)
                return false;
            a ^= 1;
        }
        return true;
    }
};