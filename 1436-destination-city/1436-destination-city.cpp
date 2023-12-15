class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> mp;
        for(auto i : paths)
        {
            mp[i[0]] = i[1];
        }

        string s = paths[0][0];
        while(mp.find(s) != mp.end())
        {
            s = mp[s];
        }
        return s;
    }
};