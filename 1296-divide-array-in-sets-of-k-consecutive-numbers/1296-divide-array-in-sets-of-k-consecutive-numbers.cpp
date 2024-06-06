class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0)
            return false;
        int x = 0;
        map<int,int> mp;
        for(auto i : nums)
            mp[i]++;
        for(int i = 0; i < n; i++)
        {
            if(i % k == 0)
            {
                x = mp.begin()->first;
                mp[x]--;
                if(mp[x] == 0)
                    mp.erase(x);
            }
            else if(mp.find(x + 1) == mp.end())
                return false;
            else
            {
                x++;
                mp[x]--;
                if(mp[x] == 0)
                    mp.erase(x);
            }
        }
        return true;
    }
};