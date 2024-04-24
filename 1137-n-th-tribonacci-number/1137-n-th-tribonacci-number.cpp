class Solution {
public:
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