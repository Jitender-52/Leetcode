class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string ans = "";
        char last = word[0];
        int count = 1;
        for(int i = 1; i < n; i++)
        {
            if(word[i] == last)
            {
                if(count == 9)
                {
                    ans += to_string(count);
                    ans += last;
                    count = 0;
                }
                count++;
            }
            else
            {
                ans += to_string(count);
                ans += last;
                last = word[i];
                count = 1;
            }
        }
        ans += to_string(count);
        ans += last;
        return ans;
    }
};