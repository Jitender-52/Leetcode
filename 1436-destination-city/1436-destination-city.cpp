class Solution {
public:
    
//     Runtime: 8 ms, faster than 75.96% of C++ online submissions for Destination City.
// Memory Usage: 11.7 MB, less than 23.80% of C++ online submissions for Destination City.
    
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