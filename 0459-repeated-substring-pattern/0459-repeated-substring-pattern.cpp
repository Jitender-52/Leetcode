class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i = 1; i <= n/2; i++)
        {
            string s1 = s.substr(0, i);
            int m = s1.length();
            bool check = true;
            int j = 0;
            for(j; j + m <= n; j += m)
            {
                if(s.substr(j, m) != s1)
                {
                    check = false;
                    break;
                }
            }
            if(check && j == n)
            {
                return true;
            }
        }
        return false;
    }
};