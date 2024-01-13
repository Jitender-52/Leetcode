class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        vector<int> v(26);
        for(auto i : s)
            v[i - 'a']++;
        for(auto i : t)
            v[i - 'a']--;
        for(auto i : v)
            ans += max(0, i);
        return ans;
    }
};