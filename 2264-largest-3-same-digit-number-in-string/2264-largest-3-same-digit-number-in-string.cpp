class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        char a = '*';
        for(int i = 1; i < n-1; i++)
        {
            if(num[i] == num[i-1] && num[i] == num[i+1])
            {
                if(a == '*')
                    a = num[i];
                else
                    a = max(a, num[i]);
            }
        }
        if(a == '*')
            return "";
        string ans = "";
        for(int i = 0; i < 3; i++)
            ans += a;
        return ans;
    }
};