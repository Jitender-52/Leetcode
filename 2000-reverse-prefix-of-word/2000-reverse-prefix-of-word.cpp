class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Prefix of Word.
// Memory Usage: 7.5 MB, less than 26.16% of C++ online submissions for Reverse Prefix of Word.
    
    string reversePrefix(string word, char ch) {
        int n = word.size();
        string ans = "";
        int i = 0;
        for(i; i < n; i++)
        {
            ans += word[i];
            if(word[i] == ch)
            {
                reverse(ans.begin(), ans.end());
                break;
            }
        }
        i++;
        for(i; i < n; i++)
            ans += word[i];
        return ans;
    }
};