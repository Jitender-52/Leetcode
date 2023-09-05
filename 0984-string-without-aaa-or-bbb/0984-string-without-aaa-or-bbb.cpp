class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";
        while(a > 0 && b > 0)
        {
            if(a > b)
            {
                ans += "aa";
                ans += 'b';
                a -= 2;
                b -= 1;
            }
            else if(a < b)
            {
                ans += "bb";
                ans += 'a';
                a -= 1;
                b -= 2;
            }
            else
            {
                ans += 'a';
                ans += 'b';
                a -= 1;
                b -= 1;
            }
        }
        for(int i = 0; i < a; i++)
            ans += 'a';
        for(int j = 0; j < b; j++)
            ans += 'b';
        return ans;
    }
};