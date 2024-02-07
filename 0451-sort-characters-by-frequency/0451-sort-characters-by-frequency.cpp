class Solution {
public:
    
//     Runtime: 15 ms, faster than 25.02% of C++ online submissions for Sort Characters By Frequency.
// Memory Usage: 11.1 MB, less than 11.70% of C++ online submissions for Sort Characters By Frequency.
    
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto i : s)
            mp[i]++;
        vector<pair<int, char>> v;
        for(auto i : mp)
            v.push_back({i.second, i.first});
        sort(v.rbegin(), v.rend());
        string ans = "";
        for(auto i : v)
        {
            for(int j = 0; j < i.first; j++)
                ans += i.second;
        }
        return ans;
    }
};