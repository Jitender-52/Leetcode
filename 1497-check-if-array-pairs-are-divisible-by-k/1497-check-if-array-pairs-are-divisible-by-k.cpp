class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;
        // for(auto i : arr)
        // {
        //     if(i < 0)
        //         mp[k + i % k]++;
        //     else
        //         mp[i % k]++;
        // }
        for (auto i : arr) 
        {
            int rem = i % k;
            if (rem < 0) 
                rem += k;
            mp[rem]++;
        }
        if(mp[0] % 2 == 1)
            return false;
        for(int i = 1; i <= k/2; i++)
        {
            if((mp[i] != mp[k-i]))
                return false;
        }
        return true;
    }
};