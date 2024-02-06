class Solution {
public:
    
//     Runtime: 25 ms, faster than 82.98% of C++ online submissions for Group Anagrams.
// Memory Usage: 22.1 MB, less than 41.23% of C++ online submissions for Group Anagrams.
    
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