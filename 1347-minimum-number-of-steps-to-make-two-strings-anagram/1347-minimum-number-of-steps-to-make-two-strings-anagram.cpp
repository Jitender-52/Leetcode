class Solution {
public:
    
//     Runtime: 39 ms, faster than 96.96% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
// Memory Usage: 16.9 MB, less than 82.29% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
    
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