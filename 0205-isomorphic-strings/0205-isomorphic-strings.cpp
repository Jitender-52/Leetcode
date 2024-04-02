class Solution {
public:
    
    bool solve(string &s, string &t)
    {
        int n = s.length();
        map<char, char> mp;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = t[i];
            else if(mp[s[i]] != t[i])
                return false;
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        return solve(s, t) & solve(t, s);
    }
};