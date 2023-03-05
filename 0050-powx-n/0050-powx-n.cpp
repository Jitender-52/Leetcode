class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        
        if(n < 0)
        {
            if(n == INT_MIN)
            {
                double half = myPow(1/x, -(n/2));
                return half * half;
            }
            return myPow(1/x, -n);
        }
        
        double half = myPow(x, (n/2));
        if(n & 1)
            return half * half * x;
        return half * half;
    }
};