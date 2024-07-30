class Solution {
public:
    
    bool isVowel(char c)
    {
        string v = "aeiou";
        for(auto i : v)
        {
            if(i == c)
                return true;
        }
        return false;
    }
    
    bool doesAliceWin(string s) {
        int count = 0;
        for(auto i : s)
            count += isVowel(i);
        return count > 0;
    }
};