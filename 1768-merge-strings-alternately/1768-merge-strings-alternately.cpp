class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        string ans = "";
        int k = 0;
        int sm = min(s1.length(), s2.length());
        while(k < sm)
        {
            ans += s1[k];
            ans += s2[k];
            k++;
        }
        while(k < s1.length())
        {
            ans += s1[k];
            k++;
        }
        while(k < s2.length())
        {
            ans += s2[k];
            k++;
        }
        return ans;
    }
};
