class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mp1;
        map<int,int> mp; // my bad using char,int here
        for(auto i : s)
            mp1[i]++;
        for(auto i : mp1)
        {
            // cout << i.first << " " << i.second << endl;
            mp[i.second]++;
        }
        int ans = 0;
        
//         for(auto i : mp)
//             cout << i.first << " " << i.second << endl;
        
        for(auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            if(it->first == 0)
                break;
            while(it->second > 1)
            {
                it->second--;
                mp[it->first-1]++;
                ans++;
            }
        }
        return ans;
    }
};