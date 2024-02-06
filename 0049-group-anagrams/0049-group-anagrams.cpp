class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, int> mp;
        vector<vector<string>> v;
        
        for(int i = 0; i < n; i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if(mp.find(s) == mp.end())
            {
                mp[s] = v.size();
                v.push_back({strs[i]});
            }
            else
            {
                v[mp[s]].push_back(strs[i]);
            }
        }
        return v;
    }
};