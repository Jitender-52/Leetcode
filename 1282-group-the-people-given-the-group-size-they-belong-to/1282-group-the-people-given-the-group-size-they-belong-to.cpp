class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++)
        {
            mp[groupSizes[i]].push_back(i);
        }
        
        vector<vector<int>> ans;
        vector<int> v;
        for(auto i : mp)
        {
            for(int j = 0; j < i.second.size(); j++)
            {
                v.push_back(i.second[j]);
                if(v.size() == i.first)
                {
                    ans.push_back(v);
                    v.clear();
                }
            }
        }
        return ans;
    }
};