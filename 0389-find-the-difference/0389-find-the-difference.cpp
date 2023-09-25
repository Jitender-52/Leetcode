class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> mp;
        for(auto i : t)
            mp[i]++;
        for(auto i : s)
            mp[i]--;
        for(auto i : mp)
        {
            if(i.second)
                return i.first;
        }
        return '*';
    }
};