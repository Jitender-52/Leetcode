class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        for(auto i : arr)
            mp[i] = 0;
        int x = 1;
        for(auto &i : mp)
        {
            i.second = x;
            x++;
        }
        for(auto &i : arr)
            i = mp[i];
        return arr;
    }
};