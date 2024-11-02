class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.length();
        int start = s[0];
        for(int i =0; i < n; i++)
        {
            if(s[i] == ' ')
            {
                i++;
                if(s[i] != start)
                    return false;
                start = s[i];
                continue;
            }
            start = s[i];
        }
        if(start != s[0])
            return false;
        return true;
    }
};