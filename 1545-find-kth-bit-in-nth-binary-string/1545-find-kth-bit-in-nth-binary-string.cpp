class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 1; i < n; i++)
        {
            string p = s;
            reverse(p.begin(), p.end());
            s += '1';
            for(auto i : p)
            {
                if(i == '0')
                    s += '1';
                else
                    s += '0';
            }
        }
        return s[k-1];
    }
};