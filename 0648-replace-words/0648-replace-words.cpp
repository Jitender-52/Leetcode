class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = sentence.length();
        map<string, int> mp;
        for(auto i : dictionary)
            mp[i]++;
        string ans = "";
        string x = "";
        for(int i = 0; i < n; i++)
        {
            if(sentence[i] == ' ')
            {
                ans += x;
                ans += " ";
                x = "";
            }
            else if(mp.find(x) != mp.end())
            {
                ans += x;
                ans += " ";
                x = "";
                while(i < n && sentence[i] != ' ')
                    i++;
            }
            else
                x += sentence[i];
        }
        if(x != "")
            ans += x;
        else
            ans.pop_back();
        return ans;
    }
};