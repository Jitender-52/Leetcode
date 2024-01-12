class Solution {
public:
    
    bool isVowel(char c)
    {
        string s = "aeiouAEIOU";
        for(auto i : s)
        {
            if(i == c)
                return true;
        }
        return false;
    }
    
    bool halvesAreAlike(string s) {
        int n = s.length();
        int i = 0, count = 0;
        for(; i < n / 2; i++)
        {
            if(isVowel(s[i]))
                count++;
        }
        for(; i < n; i++)
        {
            if(isVowel(s[i]))
                count--;
        }
        return count == 0;
    }
};