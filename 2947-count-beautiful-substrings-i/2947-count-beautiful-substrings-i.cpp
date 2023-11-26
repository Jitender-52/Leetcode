class Solution {
public:
    
    bool isVowel(char c)
    {
        string s = "aeiou";
        for(auto i : s)
        {
            if(c == i)
                return true;
        }
        return false;
    }
    
    int beautifulSubstrings(string s, int k) {
        int n = s.length(), ans = 0;
        for(int i = 0; i < n; i++)
        {
            int v = 0, c = 0;
            for(int j = i; j < n; j++)
            {
                if(isVowel(s[j]))
                    v++;
                else
                    c++;
                if(v == c && (v * c) % k == 0)
                    ans++;
            }
        }
        return ans;
    }
};