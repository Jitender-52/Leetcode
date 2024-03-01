class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;
        for(auto &i : s)
        {
            count += (i == '1');
            i = '0';
        }
        count--;
        for(int i = 0; count > 0; count--, i++)
            s[i] = '1';
        s.back() = '1';
        return s;
    }
};