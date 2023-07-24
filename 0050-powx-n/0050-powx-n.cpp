class Solution {
public:
    
    double power(double x, long long n)
    {
        if(n == 0)
            return 1;
        if(n < 0)
            return power(1/x, -n);
        double ans = power(x, n/2);
        if(n % 2 == 0)
            return ans * ans;
        else
            return ans * ans * x;
    }
    
    double myPow(double x, int n) {
        return power(x, n);
    }
};
    
    
    
//     Runtime: 4 ms, faster than 40.58% of C++ online submissions for Pow(x, n).
// Memory Usage: 6 MB, less than 35.64% of C++ online submissions for Pow(x, n).
    
    
//     double myPow(double x, int n) {
//         if(n == 0)
//             return 1;
//         if(n == 1)
//             return x;
        
//         if(n < 0)
//         {
//             if(n == INT_MIN)
//             {
//                 double half = myPow(1/x, -(n/2));
//                 return half * half;
//             }
//             return myPow(1/x, -n);
//         }
        
//         double half = myPow(x, (n/2));
//         if(n & 1)
//             return half * half * x;
//         return half * half;
//     }
// };