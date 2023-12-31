class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        int ans = -1;
        vector<int> v(26, n+1);
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, i - v[s[i] - 'a']  - 1);
            v[s[i] - 'a'] = min(v[s[i] - 'a'], i);
        }
        return ans;
    }
};