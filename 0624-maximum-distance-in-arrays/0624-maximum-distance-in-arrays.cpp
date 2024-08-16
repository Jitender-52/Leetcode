class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        map<int,int> mp;
        for(auto v : arrays)
        {
            for(auto i : v)
                mp[i]++;
        }
        int ans = 0;
        for(auto v : arrays)
        {
            int mini = 1e9, maxi = -1e9;
            for(auto i : v)
            {
                mp[i]--;
                if(mp[i] == 0)
                    mp.erase(i);
                mini = min(mini, i);
                maxi = max(maxi, i);
            }
            ans = max({ans, abs(mp.rbegin()->first - mini), abs(maxi - mp.begin()->first)});
            for(auto i : v)
                mp[i]++;
        }
        return ans;
    }
};