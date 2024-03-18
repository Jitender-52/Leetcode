class Solution {
public:
    long long countSubstrings(string s, char c) {
        map<char,int> mp;
        for(auto i : s)
            mp[i]++;
        return (mp[c] * 1LL * (mp[c]+1)) / 2;
    }
};