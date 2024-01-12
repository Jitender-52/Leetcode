class Solution {
public:
    
//     Runtime: 3 ms, faster than 52.79% of C++ online submissions for Determine if String Halves Are Alike.
// Memory Usage: 7 MB, less than 46.92% of C++ online submissions for Determine if String Halves Are Alike.
    
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