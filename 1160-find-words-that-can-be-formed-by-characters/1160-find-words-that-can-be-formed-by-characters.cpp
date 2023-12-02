class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> a(26, 0);
        for(auto i : chars)
            a[i - 'a']++;
        int ans = 0;
        for(auto s : words)
        {
            vector<int> b(26, 0);
            for(auto i : s)
                b[i - 'a']++;
            bool check = true;
            for(int i = 0; i < 26; i++)
            {
                if(a[i] < b[i])
                    check = false;
            }
            if(check)
                ans += s.length();
        }
        return ans;
    }
};