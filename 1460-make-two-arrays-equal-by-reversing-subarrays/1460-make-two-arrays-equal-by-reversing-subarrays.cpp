class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int> mp1, mp2;
        for(auto i : target)
            mp1[i]++;
        for(auto i : arr)
            mp2[i]++;
        for(auto i : mp1)
        {
            if(mp2[i.first] != i.second)
                return false;
        }
        return true;
    }
};