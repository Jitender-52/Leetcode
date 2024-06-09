class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> v(k+1, 0);
        v[0] = 1;
        int a = 0;
        int ans = 0;
        for(auto i : nums)
        {
            a = (a + i % k + k) % k; //because nums contains negative numbers also
            ans += v[a];
            v[a]++;
        }
        return ans;
    }
};