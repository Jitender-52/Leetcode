class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        int n = matches.size();

        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[matches[i][1]]++;
            if(mp[matches[i][0]])
                continue;
        }
        
        vector<int> v1;
        vector<int> v2;

        for(auto i : mp)
        {
            if(i.second == 0)
                v1.push_back(i.first);
            if(i.second == 1)
                v2.push_back(i.first);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        vector<vector<int>> ans = {v1, v2};
        return ans;
    }
};