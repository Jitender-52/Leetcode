class Solution {
public:
    
//     Runtime: 6 ms, faster than 27.80% of C++ online submissions for Sum of Square Numbers.
// Memory Usage: 7.1 MB, less than 61.35% of C++ online submissions for Sum of Square Numbers.

    
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