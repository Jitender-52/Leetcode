class Solution {
public:
    
//     Runtime: 2 ms, faster than 54.22% of C++ online submissions for Length of Last Word.
// Memory Usage: 7.7 MB, less than 20.26% of C++ online submissions for Length of Last Word.
    
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n-1;
        while(i >= 0 && s[i] == ' ')
            i--;
        int ans = 0;
        while(i >= 0 && s[i] != ' ')
        {
            ans++;
            i--;
        }
        return ans;
    }
};