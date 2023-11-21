class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int countNicePairs(vector<int>& nums) {
        map<int,int> mp;
        long long ans = 0;
        for(auto i : nums)
        {
            string s = to_string(i);
            reverse(s.begin(), s.end());
            int ri = stoi(s);
            (ans += mp[i - ri]++) %= mod;
        }
        return ans;
    }
};