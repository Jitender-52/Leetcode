class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> v;
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            for(int j = i; j < n; j++)
            {
                sum += 1LL * nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        for(int i = left - 1; i <= right - 1; i++)
            (ans += v[i]) %= mod;
        return ans;
    }
};