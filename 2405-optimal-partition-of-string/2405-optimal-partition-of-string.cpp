class Solution {
public:
    int partitionString(string s) {
        map<char,int> mp;
        int ans = 1;
        for(auto i : s)
        {
            if(mp.find(i) != mp.end())
            {
                ans++;
                mp.clear();
            }
            mp[i]++;
        }
        return ans;
    }
};