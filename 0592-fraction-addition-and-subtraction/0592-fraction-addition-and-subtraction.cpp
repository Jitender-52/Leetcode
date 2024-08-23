class Solution {
public:
    
    int gcd(int a, int b)
    {
        if(a == 0 || b == 0)
            return a + b;
        return gcd(b % a, a);
    }
    
    string fractionAddition(string expression) {
        int n = expression.size();
        int num = 0, denom = 1;
        int i = 0;
        while(i < n)
        {
            int currN = 0, currD = 0;
            bool neg = 0;
            if(expression[i] == '-')
            {
                neg = 1;
                i++;
            }
            else if(expression[i] == '+')
                i++;
            
            while(i < n && isdigit(expression[i]))
            {
                int x = expression[i] - '0';
                currN = currN * 10 + x;
                i++;
            }
            if(neg)
                currN *= -1;
            i++;
            
            while(i < n && isdigit(expression[i]))
            {
                int x = expression[i] - '0';
                currD = currD * 10 + x;
                i++;   
            }
            num = num * currD + denom * currN;
            denom = denom * currD;
        }
        int g = abs(gcd(num, denom));
        num /= g;
        denom /= g;
        return to_string(num) + "/" + to_string(denom);
    }
};