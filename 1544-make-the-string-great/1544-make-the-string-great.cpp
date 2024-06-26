class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            if(j > 0 && abs(s[i] - s[j-1]) == 32)
                j--;
            else
            {
                s[j] = s[i];
                j++;
            }
        }
        return s.substr(0, j);
    }
};