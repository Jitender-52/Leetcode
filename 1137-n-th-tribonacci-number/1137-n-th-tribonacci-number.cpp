class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-th Tribonacci Number.
// Memory Usage: 7.1 MB, less than 53.59% of C++ online submissions for N-th Tribonacci Number.
    
    int tribonacci(int n) {
        long long a = 0, b = 1, c = 1;
        
        for(int i = 0; i < n; i++)
        {
            long long temp = c;
            c = c + b + a;
            a = b;
            b = temp;
        }
        return a;
    }
};