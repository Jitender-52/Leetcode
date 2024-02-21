class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if(left == 0 || (int)log2(left) != (int)log2(right))
            return 0;
        int ans = left;
        for(long long i = left; i <= right; i++)
            ans &= i;
        return ans;
    }
};