class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        int dots = 0;
        int e = 0;
        bool check = false;
        int op = 0;
        bool num = false;
        if(s == ".")
            return false;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '.')
            {
                if(check)
                    return false;
                dots++;
            }
            if(s[i] == 'e' || s[i] == 'E')
            {
                if(!num)
                    return false;
                check = true;
                e++;
            }
            else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                return false;
            if(s[i] == '+' || s[i] == '-')
            {
                op++;
                if(i > 0)
                {
                    if(s[i-1] == 'e' || s[i-1] == 'E')
                        continue;
                    return false;
                }
            }
            if(s[i] <= '9' && s[i] >= '0')
                num = true;
        }
        
        if(!num || s[n-1] == 'e' || s[n-1] == 'E' || e > 1 || dots > 1 || s[n-1] == '+' || s[n-1] == '-')
            return false;
        return true;
    }
};