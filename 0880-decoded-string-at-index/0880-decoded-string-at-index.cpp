class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long n = 0, i = 0;
        for (i = 0; n < k; ++i)
        {
            if(isdigit(s[i]))
                n *= (s[i] - '0');
            else
                n++;
        }
        while (i--)
        {
            if (isdigit(s[i]))
            {
                n /= s[i] - '0';
                k %= n;
            }
            else if (k % n-- == 0)
            {
                string ans = "";
                ans += s[i];
                return ans;
            }
        }
        return "";

    }
};