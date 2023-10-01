class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "", x ="";
        for(int i = 0; i < n; i++)
        {
            if(s[i] == ' ')
            {
                reverse(x.begin(), x.end());
                ans += x;
                ans += ' ';
                x = "";
            }
            else
            {
                x += s[i];
            }
        }
        reverse(x.begin(), x.end());
        ans += x;
        return ans;
    }
};