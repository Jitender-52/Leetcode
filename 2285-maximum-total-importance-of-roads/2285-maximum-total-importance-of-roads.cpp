class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> v(n);
        for(auto i : roads)
        {
            v[i[0]]++;
            v[i[1]]++;
        }
        sort(v.rbegin(), v.rend());
        long long ans = 0;
        for(int i = 0; i < n; i++)
            ans += (n - i) * 1LL * v[i];
        return ans;
    }
};