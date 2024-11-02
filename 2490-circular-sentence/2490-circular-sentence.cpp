class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Circular Sentence.
// Memory Usage: 8.1 MB, less than 83.91% of C++ online submissions for Circular Sentence.
    
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