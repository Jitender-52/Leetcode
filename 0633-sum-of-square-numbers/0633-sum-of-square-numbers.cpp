class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0; i <= sqrt(c); i++)
        {
            int a = sqrt(c - i * i);
            if(i * i + a * a == c)
                return true;
        }
        return false;
    }
};