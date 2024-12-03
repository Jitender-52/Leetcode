class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        map<int,int> mp;
        for(int i = 0; i < spaces.size(); i++)
            mp[spaces[i]] = 1;
        
        string ans = "";
        if(mp[0] == 1)
            ans += " ";
        
        for(int i = 0; i < n; i++)
        {
            ans += s[i];
            if(mp[i + 1] == 1)
                ans += " ";
        }
        return ans;
    }
};