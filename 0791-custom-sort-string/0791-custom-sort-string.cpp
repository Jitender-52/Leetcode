class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mp;
        for(int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }
        string ans = "";
        for(int i = 0; i < order.length(); i++)
        {
            if(mp[order[i]] > 0)
            {
                while(mp[order[i]] > 0)
                {
                ans += order[i];
                mp[order[i]]--;
                }
            }
        }
        
        for(auto i : mp)
        {
            if(i.second > 0)
                while(i.second > 0)
                {
            ans += i.first;
                    i.second--;
                }
        }
        return ans;
    }
};