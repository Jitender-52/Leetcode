class Solution {
public:
    
//     Runtime: 117 ms, faster than 21.77% of C++ online submissions for Count Nice Pairs in an Array.
// Memory Usage: 57.4 MB, less than 35.81% of C++ online submissions for Count Nice Pairs in an Array.
    
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