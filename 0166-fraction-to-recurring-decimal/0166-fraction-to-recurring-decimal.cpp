class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long x = numerator, y = denominator;
        if(x == 0)
            return "0";
        string ans = "";
        if(x < 0 ^ y < 0)
            ans += '-';
        x = abs(x);
        y = abs(y);
        long long q = x / y;
        long long r = x % y;
        ans += to_string(q);
        if(r == 0)
            return ans;
        ans += '.';
        map<int,int> mp;
        while(r != 0)
        {
            if(mp.find(r) != mp.end())
            {
                ans.insert(mp[r], "("); // at the position where repetition started
                ans += ')';
                break;
            }
            else
            {
                mp[r] = ans.length();
                r *= 10;
                ans += to_string(r / y);
                r %= y;
            }
        }
        return ans;
    }
};