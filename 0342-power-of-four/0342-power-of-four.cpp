class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)
            return false;
        int a = log2(n) / log2(4);
        return pow(4, a) == n;
    }
};