class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto i : arr1)
            mp[i]++;
        int idx = 0;
        for(auto i : arr2)
        {
            for(int j = 0; j < mp[i]; j++)
            {
                arr1[idx] = i;
                idx++;
            }
            mp.erase(i);
        }
        for(auto i : mp)
        {
            for(int j = 0; j < i.second; j++)
            {
                arr1[idx] = i.first;
                idx++;
            }
        }
        return arr1;
    }
};