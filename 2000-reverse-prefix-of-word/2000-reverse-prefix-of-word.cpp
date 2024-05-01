class Solution {
public:
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